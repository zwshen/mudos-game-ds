#include <command.h>
#include <path.h>
// Room: /open/world3/tmr/basic/digging_street2.c

inherit ROOM;

void create()
{
	set("short", "°¨¸ô");
	set("long", @LONG
¤@±ø³sÃ´Äq³õ»P¦í¦v°Ïªº°¨¸ô¡C¥Ñ©óÄq³õªºªÅ®ğ«D±`¦Ã¿B¡A¦b°¨¸ô¨â
®Ç¦³¤j«¬ªºªÅ®ğ²M·s¾÷¡A¥ç¥Î¥i¬ï¶V«¬Å@¸n±N¨â°Ï¹jÂ÷¡A¥O¨ì©~¥Á±o¨ìµÎ
¾Aªº¥Í¬¡Àô¹Ò¡C§A¤£¸g·Nµo²{¡A¦b§A¸}ÃäªºÅ@¸n©³¯}¤F­Ó¤p¬}¡A«_¥X¤@Á\
Á\ªº[0;1;37m¥[1mÕ[1m¦[1mâ[1mÃ[1mú[1m®[1mğ[0m....
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "¬ï¶V«¬Å@¸n" : "¥Ñ¤@ºØ½¦½èª«Åé»s¦¨ªº¡A¥u¯àÅı²GÅé©M©TÅé³q¹L¡A¨Ï±o¯à°÷¹F¨ìªı¹j
¦Ã¿BªÅ®ğªº®ÄªG¡C
",
"¥Õ¦âÃú®ğ":"´²µoµÛ­»¨ıªº¥Õ¦âÃú®ğ¡A¤£ª¾Åı¨­Åé®ûº¯(immerse)¸ÌÀY·|¦p¦ó¡C\n",
]));
	set("world", "future");
	set("outdoors", "desert");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"digging_street1",
  "south" : __DIR__"digging_street3",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
        add_action("do_immerse","immerse");
}

int do_immerse(string arg)
{
        object me,*inv;
        int i;
        string buffer1,file;
        me=this_player();
        if(!arg || arg!="¥Õ¦âÃú®ğ") return 0;

        if(me->is_busy()) return notify_fail("§A¤W¤@­Ó°Ê§@ÁÙ¨S§¹¦¨¡C\n");

        if(me->query_temp("ride")) 
                return notify_fail("§Aªº®yÃMÅãµM¤£Ä@·N³­§A¤@°_¾a¶iÃú®ğ....\n");
   if(me->query_temp("killer"))
  {
    write("§A±ş¤F¤H¼È®É¤£¥i¥H¸ó¶V®ÉªÅ!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("§A§ğÀ»¤Fª±®a¼È®É¤£¥i¥H¸ó¶V®ÉªÅ!\n");
    return 1;
  }


        tell_room(environment(me),me->query("name")+"ºCºC¦aªº¾ã­Ó¨­Åéº¯¶i¥Õ¦âÃú®ğ¸ÌÀY¤F....\n",({me}) );
        inv = all_inventory(me);

        for(i=0; i<sizeof(inv); i++)
        {
        if(inv[i]->query("secured")) 
                inv[i]->delete("secured");
        if(!inv[i]->query("base_value"))
        {
        file=base_name(inv[i]);
        if((sscanf(file,"/open/world2/%s",buffer1)!=1 && sscanf(file,"/open/always/%s",buffer1)!=1 )
                || inv[i]->query_max_encumbrance() > 0)
                {
                if(inv[i]->query("equipped")) inv[i]->unequip();
                DROP_CMD->do_drop(me, inv[i]);
                }
        }
        }
        message("system", "§A¥á¤U¤@¨Ç¦h¾lªºª««~, ºCºCªº¨«¶i¥Õ¦âªºÃú®ğ¡C\n\n",me);
        me->move(NOW"anfernee/start/hall3");
        me->set("startroom",NOW"anfernee/start/hall3");
        me->save();
        message("system", "¬ğµM¤@°}ªÅ¶¡ªº§á¦±.. §A¤S¦^¨ì¤F¼ô±xªº¦a¤è¡C\n\n",me);
        tell_room(environment(me),me->name()+"¬ğµM¥X²{¦b§Aªº­±«e¡C\n",({ me }));
        me->start_busy(1);
        return 1;
}

