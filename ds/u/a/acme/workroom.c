// Room: /u/a/acme/workroom.c
#include <ansi.h>
inherit ROOM;
int welcome(object me);
int note(object me);
string get_object(object who);
void create()
{
        set("short", "[0;1;32m¬[1my[0;1;5;33m¿[1;5mÃ[0;1;36m»[1mR[1mª[1mÅ[0m");
        set("long", @LONG

     [0;1;5;37m.[0m        [0;1;5;37m.[0m       [0;1;33m¡[1m´[0m [0;1;5;37m.[0m              [0;1;5;37m.[0m    [0;1;5;37m.[0m       [0;1;5;37m.[0m
        [0;1;5;37m.[0m      [0;1;5;37m.[0m            [0;1;5;37m.[0m     [0;1;5;37m.[0m            [0;1;5;37m.[0m   [0;1;5;37m.[0m 
                            [0;7;32m¢[7m«[7;30;42m¢[7m©[0m                        [0;1;5;37m.[0m
  ¡Ë        [0;1;7;32m¢[1;7m«[1;7;32m [1;7m [0;1;32m¢[1m©[0m        [0;7;32m¢[7m«[7m [7m [7m [7m [7;30;42m¢[7m©[0m  ¡Ë
[0;7;30m [0m    ¡Ë   [0;1;7;32m¢[1;7m«[1;7;32m [1;7m [1;7m [1;7m [1;7m [1;7m [0;1;32m¢[1m©[0m ¡Ë [0;7;32m¢[7m«[7m [7m [7;47m¡[7mË[7;40m [7m [7m [7m [7;30;42m¢[7m©[0m    ¡Ë
        [0;1;7;32m¢[1;7m«[1;7;32m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [0;1;32m¢[1m©[0;30;42m¢«[0;7;32;40m [7m [7m [7m [7m [7m [7m [7m [7m [7m [7m [7m [7;30;42m¢[7m©[0m
      [0;1;7;32m¢[1;7m«[1;7;32m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [0;1;32;42m¢[1m©[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [0;32;40m¢©[0m
    [0;1;7;32m¢[1;7m«[1;7;32m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [1;7m [0;1;32m¢[1m©[0m                  [0;1;34m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~
                                        [0;1;34m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[0m
[0;1;34m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[0m                  [0;1;34m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[0m
[0;1;34m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~[1m~
[0;7;30m [0m
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"workroom1.c",
		"west" : __DIR__"workroom2.c",
		"world": "/open/world1/acme/area/hotel.c",
		"wiz": "/d/wiz/hall1",
]));

         set("light",1);
        set("valid_startroom", 1);
        set("world",1);;
        setup();
        call_other("/obj/board/acme_b", "???");
}
void init()
{
        if(!wizardp(this_player())) 
                return message_vision(HIR"\t$N¡A«ç»ò·|¶]¨ì³oÃä¨Ó¡H\n"NOR,this_player());
        else welcome(this_player());
        add_action("do_look","look");
        add_action("do_look","l");
        add_action("do_test","test");
}
int do_look(string arg)
{
        if(arg=="acme") return notify_fail("§A­n¬Ý¤°»ò¡S\n");
}
int welcome(object me)
{
	string guest;
	object acme,ob1,ob2;
	guest=query("guest");
        message_vision(HIY"\t"+me->query("name")+"¤j¤j¡A¦n¤[¤£¨£§r¡Aªñ¨Ó¥i¦n¡H...^^\n"NOR,me);
	if(acme=find_player("acme"))
	{
		if(me->query("id")!="acme")
		{
			ob1=find_object(__DIR__"workroom");
			ob2=present("acme",ob1);
			if(ob2) return 1;
			add("guest",me->query("id")+" - ");
			tell_object(me,"\t¬y¼vÁÙ¦b¦£®@¡Aµ¥¦^´N·|¨Ó©Û©I§A¡C\n");
			tell_object(acme,"\t¦³³X«È¡G"+me->query("name")+"("+me->query("id")+")¡C\n");
		}
		else {
			if(!guest) tell_object(me,"\t¤µ¤éµL³X«È¡C\n");
			else tell_object(me,"\t¤µ¤é³X«È¦³¡G\n\n\t"+guest+"\n\n");
			delete("guest");
		}
	}
	else {
		tell_object(me,"\t¬y¼v(Acme)ÁÙ¨S¤W½u®@¡A§AÀH·N³}³}§a¡A¦³¥ô¦ó·N¨£Åwªïpost¡C\n");
		add("guest",me->query("id")+" - ");
	}
	if( file_size("/u/a/acme/note") > 0 ) call_out("note",1,me);
	else return 1;
}
int note(object me)
{
	write(HIW"\n=========================  ¬y¼v³Æ§Ñ¿ý  =========================\n"NOR);
	me->start_more( read_file("/u/a/acme/note") );
	write(HIW"\n================================================================\n"NOR);
	return 1;
}
int do_test(string arg)
{
    string who;
    who = get_object(this_player());
    write("" + who + "\n");
    printf("Base_Name [%s]\n", base_name(this_player()) );
    return 1;
}

string get_object(object who)
{
    return sprintf("%O", who);
}
