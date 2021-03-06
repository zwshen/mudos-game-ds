// ★ 一般人類NPC 

#include <ansi.h>
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name( "旅客", ({ "passenger","旅客","passenger",}));
        set("long", "一個滿臉橫肉的旅客﹐正在被安全警衛盤問著。\n"
        );
        set("level",20);
        set("title","[1;33m外地人[m");
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
        set("exp",1000);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
        				
        set("str",31);			//設定屬性(可免)
        set("dex",21);			//也可以只設定 level
        set("con",33);			//其他沒設定的屬性系統就會自動產生,
        set("int",18);			//即使是相同的level也會有不同屬性.
        
        set("combat_exp",2000);		//戰熟(約在mob level的100倍左右為宜)
//        set("env/wimpy", 20);		//逃跑wimpy (20%)
        set("evil",20);			//邪惡度 20 (正的表邪惡, 負表善良)

	set_skill("blade",40);		// 技能(自定)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

//========================態度類別=================================
//   set("attitude", "friendly");   //友善的 NPC。
   set("attitude", "peaceful");   //溫和的 NPC。
//   set("attitude", "heroism");    //英雄主義的 NPC。
//   set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。
//   set("attitude", "killer");     //嗜殺成性的 NPC。


//=============================自動動作=================================
  set("chat_chance", 0 );  //動作機率
  set("chat_msg", ({       //動作內容
"旅客用力的踢了牆壁一腳!! 似乎非常生氣..\n",
(:command("say 哇靠!! 這是什麼服務態度嘛!!!"):),
(:command("say 到底要我說幾次啊~~ 這把開山刀是我剛剛撿到的.."):),
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m我叫做牛過...你問這個幹什麼?? 無聊!![m
LONG );

//set("talk_reply","你少管閒事....");
//=========================戰鬥訊息===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"旅客破口大罵 : 「可惡的傢伙∼﹗我打死你﹗」\n"NOR,
     }) );

        setup();

//==========================裝備道具=============================
      add_money("coin", 200);		//帶的錢
      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/kaisan_b")->wield();
      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk 時會執行此函式.
{
 command("smile "+me->query("id") );
 return 1;
}

void init()
{
	::init();
add_action("do_kill","kill");
}

int do_kill(string arg)
{
 if(arg=="passenger")
 {
 message_vision("[1;37m安全警衛馬上站出來對$N[1;37m說: 請不要動手, 交給我們處理就好了。[m\n",this_player());
 return 1;
 }
return 0;
}

//======================動作反應======================================
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("angry "+ob->query("id") );
		if(random(10)>7 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!!\n"
        	+"旅客(passenger)想謀殺我!! 旅客(passenger)是殺人兇手!![m\n");
                command("say 他@#$的, 老子正在氣頭上居然敢踢我!!");
                kill_ob(ob);
                }
                break;
        case "club":
                command("angry "+ob->query("id") );
                if(random(10)>6 && !ob->is_fighting())
        	{
        	shout("[1;31m"+ob->query("name")+"("+ob->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!!\n"
        	+"旅客(passenger)想謀殺我!! 旅客(passenger)是殺人兇手!![m\n");
                command("say 他@#$的, 老子正在氣頭上居然敢偷打我!!");
                kill_ob(ob);
                }
                break;
        default:
                command("say 滾遠一點!!別煩我!!");
                break;
        }
}

//======================接受反應======================================
int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("他不想收你的東西。\n");
        else if( val > 100 ) {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/1000) );
        }
        say( "旅客說道﹕多謝這位" + RANK_D->query_respect(who)
                + "﹐神明一定會保佑你的。\n");

        return 1; //有retrun 1 才會收下東西.
}

void reset()
{
        // delete("memory");
}

// ★★ 有特攻之NPC(1) 技能式特攻
// ★★★★ 職業工會導師
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("流無形" , ({ "invisible liu","liu" }) );
        create_family( HIC "ξ神武教ξ" NOR ,2,"教主");
        set("level",50);
        set("race","人類");
        set("age",65);
         set("adv_class",1);
         set("class1","神武教");
        set("gender","男性");
        set("int",100);
        // 設定屬性分配表, 每一項的值在負9至正10之間
        // 而且四項的總和要剛好等於 20                  by shengsan
        set("guild_gifts",({2,4,9,5}));
        set("guild_skills",([
               "dodge" : ({160,2,60}),
               "parry" : ({160,2,60}),
               "sword" : ({160,2,60}),
               "godsword" : ({140,2,70}),
               "meditate" : ({160,2,20}),
               "mirage-steps" : ({150,2,50}),
        ])  );
     set("guild_spells",([
                "god-fire" : ({170,2,60}),
                "god-benison" : ({170,2,50}),
        ]) );
        set_spell("god-fire",80);
        set_spell("god-benison",70);
        set_skill("force", 100);
        set_skill("mirage-steps",100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("godsword",100);
        set("long",@long
他是ξ神武教ξ的教主，提供基本的技巧訓練。你可以
使用list來看看有什麼技巧可以提供學習(train)。也可
以用advance <level或屬性> 來升級, 升級前建議先使用
level 指令來查閱所需要的經驗值。
long
);
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("cast god-fire"):),
                  (:command("exert mirage-steps"):),
                  (:command("cast god-benison"):),
        }) );
        setup();
             carry_object("/open/world1/acme/area/npc/wp/godsword.c")->wield();
}

int accept_object(object who,object ob)
{
        object plate;
        object me;
      me = this_player();

        if(ob->name()!="神武令牌")
                return 0;
        else {
                command("say 咦！！這不是師父的令牌嗎！！");
                command("say 原來師父安好，看來我是多擔心了。");
                command("smile");
                command("say 這位" +  RANK_D->query_respect(ob) + "多謝幫忙。\n");
if(me->query("class1")  ) 
{
  notify_fail("你已是"+me->query("class1")+"的弟子了，老夫就此謝過了。\n");
}
else {
            command("say 你若虛心上進，老夫就收你為徒吧！\n");
            command("say 入我教當行俠仗義，除強濟弱！\n");
            who->set("adv_class",1);
            who->set("class1","神武教");
            who->create_family("神武教",3,"教徒");
           who->set("guild_rank",HIC"神武教☉"HIG"開山祖師"NOR);
return 1;
}
       }
  return 1;     
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_force","force");
}
int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();
        me->set("no_check_class",1);    //暫時
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        me->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
//      GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
//      this_player()->delete("no_check_class");
//        return 1;
}
int do_join(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

if(me->query("class1")=="神武教") return notify_fail("你已是神武教弟子了。\n");
         if(arg!="神武教") return notify_fail("你要拜入那一個門派?\n");
     say("流無形正自發愁，並沒有發現你要加入。\n");
     say("流無形喃喃自語的道：師父他老人家不知安好，已十年八戴未通消息。\n");
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="神武教") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("你不是神武教徒。\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);

}
int do_force(string arg)
{
        string dest, cmd;
        object ob,me;
        me=this_player();
        ob=this_object();
        if( this_player()->query("id")!="acme")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式﹕force <人物> to <指令>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("這裡沒有 " + dest + "。\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"正忙著，沒有空聽你的驅使。\n");
        command(cmd);
        return 1;
}

// ★★★ 有特攻之NPC(2) 特殊能力式

#include <ansi.h>
inherit NPC;
void make_mark();

void create()
{
	set_name("銀辯",({"yin-bian","bian"}) );
	set("long","他是奧凡迪斯裡有名的修行者，聽說他擁有超能力。\n");
	set("age",30);
	set("level",40);
	set("race","人類");
	set("guild_gifts",({3,4,8,5}));
	set("evil",-10);
	set("exp_point",4);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",8);
	set("chat_msg",({
		(:command("say 這是座美麗的城市，請不要做出違法的事情喔！"):),
		(:command("smile"):),
		(: this_object(), "random_move" :),
		(: this_object(), "random_move" :),
		(: this_object(), "random_move" :),
	})	);

	set("chat_chance_combat", 47);
	set("chat_msg_combat", ({
		(:command("say 為了維護奧凡迪斯的安全，我身為巡官，一定要將作亂者就地正法！！"):),
		(: make_mark :),
//		(:command("cast mindkill"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
//	set_spell("mindkill",70);
	set_skill("staff",70);

	set("talk_reply","喔，這是座美麗的城市。請記得不要亂丟垃圾喔。");
	setup();

	carry_object(__DIR__"eq/aihun_robe")->wear();

	add_money("dollar",200);
}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 2 + random(3) )
	{
		command("say 你這個作亂者，居然為非作歹，今天被我遇到算你倒楣。");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}

}


void make_mark()
{
	object *enemy, ob;
	command("think");
	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say 哼!無法無天的"+ob->query("name")+", 我發誓要將你逐出奧凡迪斯。");
	ob->add_temp("quest/aovandis",1);	// 將欺負市民的人做上標記
	this_object()->set("helpready/"+ob->query("id"),1);	// 與 id 結仇

}

int special_attack(object me,object victim,int hitrole)
{
	int damage,c;

	if(!victim) return;
	if(me->query("mp")<20) return;
	me->receive_damage("mp",20);
	command("say "+victim->query("name")+"，讓你看看我超能力的利害。");


	tell_room(environment(me),"\n"+me->query("name")+"突然身子往後退了一步\n");
	tell_room(environment(me),"\n你看到他的雙手自然的垂下，雙目變得異常的有神。\n");

	if( victim->query_int() < random(150) )
	{
	    victim->add_busy(2);
	    message_vision(HIR"\n$N突然對周遭的環境充滿著恐懼，$N的行動好像被限制住了。\n",victim);
	    damage = random(300)+query_int()*5;
	    damage = damage/2+random(damage/2);
	    c=victim->quer_shield();
	    damage = damage-c/2-random(c/2);
	    if(damage<0) damage=0;
	    damage = COMBAT_D->Merits_damage(me,victim,damage,"sou");
	    victim->receive_damage("hp", damage, me );
	    if(damage>0)
	    	message_vision(HIR"\n$N突然被莫名的力量所打中，口吐鮮血，整個人被打在牆壁上動彈不得。\n"NOR,victim);
	    else
		message_vision(HIW"\n由於$N的靈力勝過 "+me->query("name")+" 一籌，活生生地接下了這股莫名之力。\n"NOR,victim);

	    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
	    if(victim->query_temp("apply/show_damage") || victim->query_temp("show_damage") )
	        tell_object(victim,HIR"("+damage+")"NOR+" ("+victim->query("hp")+"/"+victim->query("max_hp")+")");
	    message_vision("\n",victim);
	    if(wizardp(victim) && victim->query("env/debug"))
	        tell_object(victim,"  造成"+damage+"點傷害!!\n"); 
	    COMBAT_D->report_status(victim);	

	}
	else message_vision("\n莫名之力直直攻向$N，結果被$N機靈的化解了。\n",victim);

 	me->start_busy(1);

}


// ★★★★ 複雜動作之NPC




// ★★★★★ 附加功能之NPC (並參見其他範例)

#include <ansi.h>
#define DRAGON_M "/open/always/dragon_mark"
inherit NPC;
void create()
{
//=========================基本設定==========================

        set_name( "幫會使者", ({ "club messager","messager"}));
        set("long", "一個黑衣人。\n你如果遺失了幫會信物, 可以打(checkclub)向他申請一個新的信物。\n"
        );
        set("level",1);
        set("title","[1;33m義工[m");
        set("gender", "男性");
        set("race", "人類");
        set("age", 1);
        set("exp",10);		//玩家殺死會得到exp/10 (可免)
        				//建議不要自己設exp. 由系統決定
        				//以免不同wiz寫的mob 會出現太大的差異
        				
        set("str",1);			//設定屬性(可免)
        set("dex",1);			//也可以只設定 level
        set("con",1);			//其他沒設定的屬性系統就會自動產生,
        set("int",1);			//即使是相同的level也會有不同屬性.
        
        set("combat_exp",1);		//戰熟(約在mob level的100倍左右為宜)
//        set("env/wimpy", 20);		//逃跑wimpy (20%)
        set("evil",-20);			//邪惡度 20 (正的表邪惡, 負表善良)

	set_skill("blade",40);		// 技能(自定)
	set_skill("parry",20);		//
	set_skill("dodge",30);		//

//========================態度類別=================================
//   set("attitude", "friendly");   //友善的 NPC。
   set("attitude", "peaceful");   //溫和的 NPC。
//   set("attitude", "heroism");    //英雄主義的 NPC。
//   set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。
//   set("attitude", "killer");     //嗜殺成性的 NPC。


//=============================自動動作=================================
  set("chat_chance", 0 );  //動作機率
  set("chat_msg", ({       //動作內容
(:command("sigh"):),
(:command("shrug"):),
}) );

//===========================問題回答==================================
set("inquiry/name", @LONG
你問這個幹什麼?? 無聊!!
LONG );


//=========================戰鬥訊息===========================
     set("chat_chance_combat", 17);
     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"旅客破口大罵 : 「可惡的傢伙∼﹗我打死你﹗」\n"NOR,
     }) );

        setup();

//==========================裝備道具=============================
//      add_money("coin", 200);		//帶的錢
//      carry_object(__DIR__"item/bag");
//      carry_object(__DIR__"wp/kaisan_b")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}

int talk_action(object me)	//talk 時會執行此函式.
{
 command("say 你如果掉了幫會信物就來找我申請(checkclub)吧!");
 return 1;
}

void init()
{
	::init();
add_action("do_checkclub","checkclub");
}

int do_checkclub(string arg)
{
	object me,ob,mark;
	string clubname;
	me=this_player();
	if(mark=present("club_mark",me)) return notify_fail("你已經有幫會信物了。\n");
	
	if(!clubname=me->query("club/name")) return notify_fail("你並沒有參加幫會的紀錄。\n");
	switch(clubname)
	{
		case "狂龍幫":
				ob=new(DRAGON_M);
				ob->move(me);
				message_vision("$N拿了一"+ob->query("unit")+ob->name()+"給$n。\n",this_object(),me);
				me->save();
				return 1;
		default:
			return notify_fail("使者還沒有拿到這個幫派信物。\n");
	}

}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("他不想收你的東西。\n");
        else if( val > 1000 )
        {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/10000) );
        }
        say( "使者說道﹕多謝這位" + RANK_D->query_respect(who)
                + "﹐神明一定會保佑你的。\n");

        return 1;
}
