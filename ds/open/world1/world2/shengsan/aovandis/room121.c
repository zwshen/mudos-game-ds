// ���Z�}��

// LV 1~50
#include <ansi.h>
#include <path.h>
inherit ROOM;

string l_cabinet();
string l_rack();

void create()
{
	set("short", HIC"���߹Ϯ��]�\\����"NOR);
	set("long", @LONG
�o���\���Ǹ̪����x���m���״I�A�q��N�̬y�檺�ɩ|���x��M�~��
�޳N�����x�����A�C�����x�Ҿ�����\��b�j���i���d(cabinet)���C�t
�~�٦��U�a���������ȱ��b�[�l(rack)�W�C�b�𨤦��x�v�L��(photostat)
�ѤH�ƻs�v�L�C��W���ӧi�ܵP(note)�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "south": __DIR__"room122",
	    "down" : __DIR__"room073",
            ]));

	set("objects", ([
		__DIR__"npc/obj/photostat":1,
	]));

	set("item_desc", (["note":@NOTE
�G�i�P�W�g��:

	�o�̪��������x�ä���~�ɡA�p�G�ݭn�̭�����ơA
	�Цh�h�Q�μv�L��(photostat)�C
	�p�G�n���[�W�����x�Х� getmagazine
NOTE
        ,"photostat":@NOTE
�o�x�v�L���ݰ_�ӫD�`�����šA�p�G�ݭn�v�L��ơA�Υ��N�S���F�C
NOTE
        ,"cabinet": (: l_cabinet :)
        ,"rack": (: l_rack :)
	]) );

	set("no_clean_up", 0);
	set("no_recall",1);
	set("light", 1);

	set("magzroom",SHENGSAN2"aovandis/magzroom");

	setup();
}

void init() 
{
//	::init();
	add_action("do_getmagazine","getmagazine");
}

int sort_item(object ob1, object ob2)
{
	return strcmp(base_name(ob1),base_name(ob2));
}

int do_getmagazine(string arg)
{
	object magzroom,me,ob;

	if(!arg) return notify_fail("getmagazine ���x\n");
	if(!magzroom=load_object(this_object()->query("magzroom"))) return 0;
	me = this_player();

	if(ob=present(arg,magzroom))
	{
		if(!me) return 0;
		if(!ob->is_magzine())
			write("�u"+ob->query("name")+"�v�ä��O�@�����x��C\n");
		else
		{
	 		ob->move(me);
	 		magzroom->save();
			me->save();
			message_vision("$N�q�j���i���d�����X�@���u"+ob->query("name")+"�v�C\n",me);
		}
	}
	else
		write("�ڡH�A�T�w���u"+arg+"�v�ܡH�C\n");

	return 1;
}

string l_cabinet()
{
	object *magzs,magzroom;
	int i,j,gotit;
	string line;

	if(!magzroom=load_object(this_object()->query("magzroom"))) return "?_?\n";
	if(!magzroom) return "?_?\n";
	magzs = all_inventory(magzroom);
	magzs = sort_array(magzs, "sort_item", this_object());

	line = sprintf(	"============================================================\n"
			"=    ��                                      �x    = �� �q =\n"
			"============================================================\n",);
	for(i=0;i<sizeof(magzs);i++)
	{
		if(!magzs[i]->is_magzine())
			continue;
		line += sprintf(
			"= %-26s%-22s = %5d =\n",
			magzs[i]->query("name"),
			"("+magzs[i]->query("id")+")",
			1);
		gotit++;
	}
	if(gotit)
		line += sprintf("============================================================\n");
	line += sprintf("�@�j�M�� %d ���ŦX���󪺸��...\n",gotit);

	this_player()->start_more(line);

	return "";
}

string l_rack()
{
	return "�o�Ӭ[�l�W��ۤ��ѳ̷s�����ȡC\n";
}