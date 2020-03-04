// Room: /u/l/luky/room/pearl_17.c
#include <ansi.h>
inherit ROOM;
inherit MOBROOM;	//»Ý©ñ¦b inherit ROOM; ¤§«á
void create()
{
	set("short", HIG"Às½¼²Ä¤G¹êÅç³õ"NOR);
	set("long", @LONG

[1;31m                                     ¢d¢d¢d¢d¢d¢d¢d¢d
                                   ¢y[41m¢i¢i¢i¢i¢i¢i¢i¢i[40m¢j[m
¡Ä¡Ä¡Ä¡Ä¡Ä   §A¥¿¨«¦b¼ö¾xªº¤jµó¤W¡C¡Ä[30;47mùø¡Ý¡Ý¡Ý¡Ý¡Ý¡Ýùø[m¡Ä¡Ä¡Ä
"  .   -   ³\¦h·í¦aªº¦~»´¤H¦b³o¸Ì»E  [30;47mùø[35m ¦Û°Ê³c½æ¾÷[30m ùø[m     "
:      -   ·|²á¤Ñ¡C§A¬Ý¨ìªFÃä¦³¤@´É  [30;47mùø¡Ý¡Ý¡Ý¡Ý¡Ý¡Ýùø[m  "  :
= ."   -   ¤j©Ð¤l¡A¤H¨Ó¤H©¹ªº¦n¤£¼ö  [30;47mùø¡°¡°ùúùû¡°¡³ùø[m     =
==-  " -   ¾x¡C®ÇÃä¦³¤@¥x¦Û°Ê³c½æ¾÷  [30;47mùàùùùùùäùäùùùùùâ[m   -==
¡Ã¡Ã¡Ã¡Ã¡Ã ¡C                      ¡Ã[30;47mùø[32mInsert coins[30mùø[m¡Ã¡Ã¡Ã
                                     [30;47mùà¢¤¢¤¢¤¢¤¢¤¢¤ùâ[m


LONG
	);
set("objects",([
// __DIR__"automat":1,
]));
set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lukylab1",
]));
set("item_desc",([
  "automat":"¤@¥x©|¥¼±Ò¥Îªº¦Û°Ê³c½æ¾÷¡C\n",
  "¦Û°Ê³c½æ¾÷":"¤@¥x©|¥¼±Ò¥Îªº¦Û°Ê³c½æ¾÷¡C\n",
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