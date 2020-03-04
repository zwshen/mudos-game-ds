#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short","[1;35m¸T³¬«Ç[0m");
set("long", @LONG
³o¸Ì¬O¬P»Ú¶¡¤§¨s·¥ºÊº»¡C·|¨Ó¨ì³oªº³£¬O--ª±MUD¤£¦u³W©wªº¤H¡C
­ü~~~§r~~~§r~~~~  ¦n¦n¤Ï¬Ù§a!!!
­@¤ßªºµ¥«á¤j¯«ªº§P¨M§a!
LONG
       );
set("light",1);
set_temp("prision",1);
delete_temp("prision");
set("objects", ([ /* sizeof() == 2 */
]));
setup();
}
void init()
{
	if(wiz_level(this_player()) > wiz_level("(wiz)"))
	{
		tell_object(this_player(),"ÄÀ©ñ½Ð¥Îfree <id>\n");
		add_action("do_free", "free");
		return;
	}
	this_player()->set_temp("out_of_power",1);
        add_action("no_quit", "quit");
        add_action("no_quit", "Q");
        add_action("no_kill", "kill");
        add_action("no_goto", "home");
        add_action("no_goto", "recall");
        add_action("no_quit", "fight");
        add_action("no_goto", "goto");
        add_action("no_rm",   "rm");
        add_action("no_dest", "dest");
        add_action("no_more", "more");
        add_action("no_cat",  "update");
        add_action("no_cat",  "cat");
        add_action("no_edit", "edit");
        add_action("no_tell", "clone");
        add_action("no_tell", "mkroom");
        add_action("no_tell", "shutdown");
        add_action("no_tell", "rest");
        add_action("no_tell", "connect");
        add_action("no_tell", "saveroom");
        add_action("no_tell", "localcmds");
        add_action("no_tell", "cp");
        add_action("no_tell", "tell");
        add_action("no_tell", "beep");
        add_action("no_tell", "chat");
        add_action("no_tell", "chat*");
        add_action("no_tell", "music");
        add_action("no_tell", "music*");
        add_action("no_tell", "rumor");
        add_action("no_tell", "wiz");
        add_action("no_tell", "wiz*");
        add_action("no_tell", "es");
        add_action("no_tell", "es*");
        add_action("no_tell", "gwiz");
        add_action("no_tell", "twiz");
        add_action("no_tell", "sys");
        add_action("no_tell", "ls");
        add_action("no_tell", "shout");
        add_action("no_call", "call");
        add_action("no_dest", "smash");
        add_action("do_fuck", "fuck");
        add_action("no_fly","fly");
        add_action("no_jump","jump");
        add_action("no_summon","summon");
        add_action("no_suicide", "suicide");
}

int no_suicide(string str)
{
     write(HIY"·Q¦º¤]¤£¬O¨º»ò®e©öªº..§O¥H¬°suicide´N¨S¨Æ¤F  :( \n"NOR);
        return 1;
}
int no_quit(string str)
{
     write(HIY"³Q§ì¤F..ÁÙ·Q·È..§O¥H¬°quit´N¨S¨Æ¤F  :( \n"NOR);
        return 1;
}
int no_goto(string str)
{
     write(HIC"«z­ù°Ç!!§A¥H¸g¦¨¤F¥}¥Ç¤F..ÁÙ·Q¶]????\n"NOR);
        return 1;
}
int no_kill(string str)
{
write("³o¸Ì¸T¤î¦³¥ô¦ó¦å¸{ªº¼É¤O¨Æ¥óµo¥Í¡C\n");
        return 1;
}
int no_more(string str)
{
     write(HIY"·Q¥Îmore °½¬Ý³oªºÀÉ³á...ªù³£¨S¦³...\n"NOR);
        return 1;
}
int no_rm(string str)
{
        write("¤°»ò?!³QÃö¤F´N¤°»òÅv¤O³£¨S¤F, ÁÙ·Qrm!!\n");

       return 1;
}
int no_dest(string str)
{
        write("§O·QºR·´³o¸Ì!!§i¶D§A³o¸Ì¬O¤£¯àºR·´ªº!!\n");
        return 1;

}
int no_cat(string str)
{
        write("§Ú¬O¿ß¡ã¡ãØp¡ã¡ãØp¡ã¡ãØp¡ã¡ã\n");
        return 1;
}
int no_edit(string str)
{
    write(HIG"§A·Q¥ÎEDIT°½§ï³o¸Ì°Ú..ªù³£¨S¦³!!!\n"NOR);
       return 1;
}
int no_call(string str)
{
       write("CALL!!«z ­ù «¨ B.B.CALL «¨\n");
        return 1;
}
int do_fuck(string str)
{
        object ob;
        ob = this_player();
        ob->reincarnate();
ob->move("/u/s/sammy/pkroom");
        return 1;
}

int do_free(string str)
{
        object ob,who;
        ob = this_player();
        if(!who=present(str,this_object())) return notify_fail("ÄÀ©ñ½Ö?\n");
	message_vision("$N±N$nÄÀ©ñ¤F!\n",ob,who);
	who->move("/open/world2/anfernee/start/login");
        who->delete_temp("out_of_power");
        return 1;
}


int no_fly(string str)
{
        write("«¢«¢«¢~~~§A¬O´¡¯Í¤]Ãø­¸¤F~~~~~¨þ¨þ~~:p\n");
        return 1;
}
int no_jump(string str)
{
        write("­ó!!!§A¸õ??§A­n¸õ¥h¨º°Ú???????\n");

return 1;
}
int no_summon(string str)
{
        write("¼K¼K....·Q§ì¤H¨Ó³­§A°Ú???????¬Ù¬Ù§a!!!!!\n");
        return 1;
}
int no_tell(string str)
{
write("[1;33m·Q§@Ô£?³£¦b¦Y¨c¶º¤FÁÙ·Q°µ©Ç°Ú¡ã¡ã¡ã[0m");
write("\n");
return 1;
}
