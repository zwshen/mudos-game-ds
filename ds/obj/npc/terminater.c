// demongorgon.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name( HIW "Ｔ２０００型終結者" NOR, ({ "terminater" }) );
	set("long",
		"新型終結者神情倨傲地站在你面前﹐他的眼神散發出一股令人窒息\n"
		"的可怕殺氣, 壓得你幾乎喘不過氣來﹐你的腦裡似乎有一個聲音在\n"
		"訴你﹕「 快 離 開 這 裡 ﹗﹗」\n");

	set("age", 7777);
	set("level", 100);
	set("max_hp", 5000);
	set("max_mp", 5000);
	
	set("str", 100);
	set("int", 100);
	set("con", 100);
	set("dex", 100);

	set("combat_exp", 5000000);

	set_skill("staff", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

    set_temp("apply/attack", 2500);
    set_temp("apply/defense", 2500);
    set_temp("apply/armor", 2500);
    set_temp("apply/damage", 2500);
      set_temp("apply/shield", 2500);


	setup();

	carry_object(__DIR__"obj/demon_staff")->wield();
}

void start_shutdown()
{
	if( geteuid(previous_object()) != ROOT_UID ) return;
	LOGIN_D->set_reboot(3);
	message("system",
		HIY	"\n\n 嗶──嗶──嗶──嗶──嗶嗶─\n\n"
		HIW	"超級系統─"HIG"愛瑪"HIW"─發出警告﹕\n\n"
		HIC	"\t\t\t自 動 毀 滅 裝 置 準 備 終 了 ﹗\n\n"
		HIC	"\t\t\t三 分 鐘 後 啟 動 毀 滅 系 統 ﹗\n\n"
		HIR	"\t\t\t\t◢███◣\n"
			"\t\t\t\t        █\n"
			"\t\t\t\t        █\n"
			"\t\t\t\t  ███◤\n"
			"\t\t\t\t        █\n"
			"\t\t\t\t        █\n"
			"\t\t\t\t◥███◤\n"NOR,
		users() );
	call_out("countdown", 60, 3);
}

private void countdown(int min)
{
	object *user;
	int i;
	min--;
	if( min == 2 )
	{
		LOGIN_D->set_reboot(2);
		message("system",
		HIR	"\n\n\t\t\t\t◢███◣\n"
			"\t\t\t\t        █\n"
			"\t\t\t\t        █\n"
			"\t\t\t\t◢███◤\n"
			"\t\t\t\t█\n"
			"\t\t\t\t█\n"
			"\t\t\t\t◥███◤\n\n"
		HIW	"\t\t── 毀 滅 系 統 將 於 二 分 鐘 後 啟 動  ﹗ ──\n\n" NOR,
			users() );
		call_out("countdown", 60, min);
	} else
	if( min == 1 )
	{
		LOGIN_D->set_reboot(1);
		message("system",
		HIR	"\n\n\t\t\t\t     ◢\n"
			"\t\t\t\t   ◢█\n"
			"\t\t\t\t     █\n"
			"\t\t\t\t     █\n"
			"\t\t\t\t     █\n"
			"\t\t\t\t     █\n"
			"\t\t\t\t   ◢█◣\n\n"
		HIW 	"\t\t── 毀 滅 系 統 將 於 一 分 鐘 後 啟 動  ﹗ ──\n\n" NOR,
			users() );
		user=users();
		for(i=0;i<sizeof(user);i++)
		{
			user[i]->save();
			tell_object(user[i],"自動儲存完畢﹗\n");
		}
		call_out("countdown", 60, min);
	} else
	if(!min)
	{
		message("system",
		HIR	"\n\n\t\t\t\t◢███◣\n"
			"\t\t\t\t█      █\n"
			"\t\t\t\t█      █\n"
			"\t\t\t\t█      █\n"
			"\t\t\t\t█      █\n"
			"\t\t\t\t█      █\n"
			"\t\t\t\t◥███◤\n\n"
		HIW "\t\t 毀 滅 系 統 開 始 進 入 啟 動 程 序 ˙˙˙ \n\n" NOR,
			users() );
		call_out("do_shutdown", 3);
	} else
	{
		message("system",
		HIW "\n\n\t\t── 毀 滅 系 統 將 於 " + chinese_number(min) + " 分 鐘 後 啟 動  ﹗ ──\n\n" NOR,
		users() );
		call_out("countdown", 60, min);
	}
}

private void do_shutdown()
{
    foreach(object tmp in children("/obj/user"))
                if( file_name(tmp) != "/obj/user" )tmp->save();
	message("system",@DOWN
	
[1;37m                   ─ 自 動 毀 滅 裝 置 已 啟 動 ─
[0;31m
	                          ______
	                       .-"      "-.
	                      /            \
	          _          |     ＤＳ     |          _
	         ( \         |,  .-.  .-.  ,|         / )
	          > "=._     | )(__/  \__)( |     _.=" <
	         (_/"=._"=._ \/     /\     \/ _.="_.="\_)
	                "=._"(_     ^^     _)"_.="
	                    "=\__|IIIIII|__/="
	                   _.="| \IIIIII/ |"=._
	         _     _.="_.="\          /"=._"=._     _
	        ( \_.="_.="     `--------`     "=._"=._/ )
	         > _.="                            "=._ <
	        (_/                                    \_)


[1;31m 你聽到附近傳來一聲前所未有的巨大爆炸聲響 ﹗所有的一切都在瞬間陷入絕對的黑暗....[0m

DOWN
,users() );
	shutdown(0);
}

void die()
{
	object ob;

	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);
	LOGIN_D->set_reboot(0);
	if( !ob ) return;
	// 做紀錄
	log_file("static/reboot","Reboot terminated by "+ob->query("id")+" at "+ctime(time())+"\n");

	message("system",
		HIW "\n\n\t── 自 動 毀 滅 程 序 已 被 " + ob->name(1) + " 中 斷 ──\n\n"
		    "\n\n\t ........ 自毀命令解除完成。\n\n" NOR,
		users() );
	destruct(this_object());
}
