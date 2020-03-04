// Room: /d/wiz/hall2.c
#include <path.h>
inherit ROOM;

void create()
{
 set("short", "Â¾·~¬ã¨s«Ç");
 set("long", @LONG
³o­Ó¥Õ¦âªº©Ð¶¡´N¬O¸ê²`§Å®v­Ì¤½§G·sÂ¾·~©M¤j¯«­Ìµoªí·s³W©w
ªº¦a¤è¡A¥|©PÂ\µÛ³\¦h¤jÅKÂd¡A¸Ì­±³£¬O§Å®v­Ìªº¬ã¨s¤ß±o³ø§i¡A¯à
°÷¨Ó¦¹¬ã²ßªº§Å®v³£¤w¸g¦³¬Û·íµ{«×ªº¸gÅç»P¯à¤O¡C¹Ú¤Û°Ï°ìªº§Å®v
¥²¶·¥ýµoªí°Ï°ì¤~¦³¸ê®æ¨Ó¦¹¾Ç²ß¡C¦³Ãö°Ï°ìªº°ò¥»³W©w»Pª`·N¨Æ¶µ
½Ð¥Î < [1;34mabout guild[m > ¬d¸ß¡C©¹¥_¨«·|¦³¤@³s¦êªº¾É®v½d¨Ò¡C

  [¦¹³B´£¨Ñcount«ü¥OÅý§Å®v¦ôºâ¦UºØ¤£¦P§Þ¯àÃø«×©Ò¹ïÀ³ªºªá¶O]

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall_area",
    "up"     : __DIR__"hall_arch",
    "east"   : __DIR__"hall_skill",
    "west"   : __DIR__"hall_spell",
    "north"  : __DIR__"hall_master",
//    "south"   : __DIR__"hall_special",
 ]));

 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/guild_b", "???");
}

void init()
{
 add_action("do_help","about");
 add_action("do_count","count");
}

int do_help(string arg)
{
 if(arg=="guild")
 {
   if( file_size("/doc/wiz/guild.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/guild.txt") );
    write("\n");
   } else write(" SORRY. »¡©úÀÉ©|¥¼«Ø¥ß. \n");
  return 1;
 }
 return 0;
}

int do_count(string arg)
{
	int hard,i,exp_sum=0,money_sum=0;
	if(!arg || sscanf(arg,"%d",hard)!=1) return notify_fail("«ü¥O: count <Ãø«×­È>¡C\n");
	printf("Ãø«×­È: %d \n",hard);
	if( hard > 999 || hard < 1) return notify_fail("½Ð­«³]¤@­Ó1¨ì999ªºÃø«×­È¡C\n");
	for(i=1;i<100;i++)
	{
		exp_sum=exp_sum+(i*i*hard/50);
		money_sum=money_sum+(i*i*hard/70);
		if(i%10==0) printf("§Þ¯àµ¥¯Å:[%3d] ¸gÅç²Ö­p:[%8d]  ¾Ç¶O²Ö­p:[%8d]\n",i,exp_sum,money_sum);
	}
	printf("§Þ¯àµ¥¯Å:[ 99] ¸gÅç²Ö­p:[%8d]  ¾Ç¶O²Ö­p:[%8d]\n",exp_sum,money_sum);
	return 1;
}