// Room: /u/l/luky/room/pearl_16.c
#include <ansi.h>
inherit ROOM;
inherit MOBROOM;	//»Ý©ñ¦b inherit ROOM; ¤§«á
void create()
{
	set("short", HIG"Às½¼²Ä¤@¹êÅç³õ"NOR);
	set("long", @LONG

  §A¥¿¦ì©óºÑ¹pº¸Âíªº¬Ã¯]¥_µó¡C¥_¤è¬O¥»Âí¥D­nªº°Ó©±¡A¦pªG§A©|
¦³¦h¾lªº¸Ë[1;33m ¢x       ¢d¢e¢f¢g¢g¢g¢f¢e¢d             ¢x[m ³Æ¡A¤£
§«¨Ó¦¹¤¤[1;33m   ¡¶¢d¢e¢f[m¢x¢¨¢©¢x¢¨¢©¢x¢¨¢©¢x[1;33m¢f¢e¢e¢d¢d¢c¡¶[m¤ß»P¨ä
¥L«_ÀIªÌ ¢y ¢x ¥Ð¥Ð¢x¥Ð¥Ð¢x¥Ð¥Ð¢x¥Ð¥Ð¢x ¥Ð ¥Ð ¢x¥Ð ¢j¢k ¥æ´«
         ¢y ¢x[33m¡Ä¢c¢d¢e¢e¢f¢f¢f¢f¢f¢e¢e¢d¢c¡Ä[m  ¢x   ¢j¢k
¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã :¢­  ¢¨¢© ¢¨¢© ¢¨¢©  ¢¬: ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã
:      -         :¢y  ¡_  ùúùùùû  ¡_  ¢j:[1;35m¡i¸Ë³Æ¥æ´«¤¤¤ß¡j[m  :
= ."   -       - :¢y  ¡ò[1;34m   ¢i¢i[m   ¡ò  ¢j:                  =
==-  " -       - :¢y[34m       ¢i¢i[m       ¢j:  -       - .   -==
¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã  ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã

LONG
	);
set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"lukylab2",
  "east" : __DIR__"workroom1",
]));
	set("no_clean_up", 0);
        set("light",1);
	set("chance",50);	//«h¦³ 50% ªº¾÷²v·|¥X²{©Çª«.
	set("mob_amount",3);	//«h³Ì¦h¥X²{¤T­Ó©Çª«.
	set("mob_object",({	//³]©w©Çª«ÀÉ¦W.
	"/open/world2/anfernee/start/npc/bug",
	"/u/l/luky/npc/mosquito"
	}) );
	setup();
	
	//ª`·N, Ä~©ÓMOBROOM«á µ´¤£¥i¥H¦³ replace_program(ROOM);
}

void init()
{
        ::init();	//ª`·N, ­Y¬O¦³Ä~©ÓMOBROOMªºroom­n¥Î¨ìinit(),«h»Ý¥[³o¤@¦æ!!

        add_action("d_creat","creat");
        add_action("d_stop","stop");
}

int d_stop(string arg)
{
 this_object()->set_temp("stop_creat",1);
 tell_object(this_player(),"©Çª«¦a¹p¤wÃö³¬!\n");
 return 1;
}

int d_creat(string arg)
{
 this_object()->set_temp("stop_creat",0);
 tell_object(this_player(),"©Çª«¦a¹p¤w¶}±Ò!\n");
 return 1;
}