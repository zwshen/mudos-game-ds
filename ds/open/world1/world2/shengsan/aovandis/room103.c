// ���Z�}��

// LV 1~50
#include <ansi.h>
#include <path.h>
#include <command.h>
inherit ROOM;

void create()
{
	set("short", HIC"�p����"NOR);
	set("long", @LONG
�A�o�{�@�y�p�����b�o�̡A���O�o�䤣�X����i�H�i�h����k�A�]�\
�o�̬O���L�i�X�@�ɪ��X�J�f�a�C
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
        "out": __DIR__"room083",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("item_desc",([	
	"���e" : "�@�T���b����W�����e�A���e�̦��@�첻�M���զ�ѤH���V�A�L���ۡC\n"+
	"�A�o�{���e�U�観���K��(ring)�C\n",
	])	);
	set("hide_item_desc",([	
	"ring" : "�@���^�b����W���K���A�i��`�`���H�h�԰�(pull)���ҥH�~�S���áC\n",
	])	);
	setup();
}

void init()
{
 add_action("do_pull","pull");
 add_action("do_out","out");
  tell_object(this_player(),"�A�o�{�A�Ө�F�@�ӯ������a��C\n");
}

int do_pull(string arg)
{
 object me,*inv;
 int i;
 string buffer1,file;
 me=this_player();
 if(!arg) return 0;
 if(me->is_busy()) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
 if(me->query_temp("ride")) return notify_fail("�A�M�۪F�褣��K�a�L�h���K���C\n");
   if(me->query_temp("killer"))
  {
    write("�A���F�H�Ȯɤ��i�H��V�ɪ�!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("�A�����F���a�Ȯɤ��i�H��V�ɪ�!\n");
    return 1;
  }

 
  if(arg=="ring" || arg=="�K��")
  {
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
    if(inv[i]->query("secured")) inv[i]->delete("secured");
    if(!inv[i]->query("base_value"))
    {
     file=base_name(inv[i]);
     if(sscanf(file,"/open/world1/%s",buffer1)!=1
     && sscanf(file,"/open/always/%s",buffer1)!=1 )
     {
      if(inv[i]->query("equipped")) inv[i]->unequip();
      DROP_CMD->do_drop(me, inv[i]);
     }
    }
   }
   tell_room(environment(me),me->name()+"�ԤF���K���A��M�o�ͤ@�}�ɪŪ��ᦱ�C\n",({ me }));
   message("system", "�A�ΤO���ԤF�K���@��A��M���ѱۦa��C\n\n",me);

   me->move(NOW"anfernee/start/nowroom");
   me->set("startroom",NOW"anfernee/start/nowroom");
   me->save();
   me->start_busy(1);
   message("system", "��M�@�}�Ŷ����ᦱ�A�A�S�^��F���x���a��C\n\n",me);
   tell_room(environment(me),"��M�@�}�j���A"+me->name()+"�����b�A���侮�E�����C\n",({ me }));
   return 1;
  } 
 return 0;
}

int do_out()
{
if(this_player()->query_temp("now_old_city"))
  this_player()->move("/open/world2/shengsan/aovandis/room083");
else this_player()->move("/open/world2/lichi_town_2/map_5_26");

  return 1;
}
