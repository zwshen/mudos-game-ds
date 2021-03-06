// /std/char/guildmaster.c		Edit by shengsan@SD	1999.04.23
// 版本: V1.04.00
// 注意事項:
// 0. 修改此檔時, 未經 Shengsan 同意, 不得刪除或修改此檔.
// 1. V1.02.00 版以後, 工會導師可以不用繼承此檔, 只要用將適當的函式引用即可.
// 2. 工會導師要使用此檔內的函式, 此工會導師必須要有完整的職業歷程記錄
//    也就是說, 玩家身上有的職業資料, NPC一樣也不能少, 其中包括:
//    a. adv_class: x	x = 數值(1~2)
//       此參數是說明此玩家或NPC目前的職業是第幾級, 1 就是第一級, 也就是最初
//       的職業等級, 2 就是第二級, 依此類推...
//    b. class1: x       x = 職業字串(英文)
//       這是第一級職業的職業英文名稱, 不管此玩家或NPC目前為第幾級的職業, 這
//       個參數一定要定義, 否則程式就不會正常工作... 記住, 職業歷程要完整...
//    c. class2: x  x = 職業字串(英文)
//       這是第二級職業的職業英文名稱...
//
// 3. 工會導師可以教授的技能列表
//    其格式範例如下:
//        set("guild_skills",([	// 難度, 等級1可學到的技能等級倍率, 上限
//            "dodge"    : ({32,2,50}), //表示難度是32, 能學的等級是2*等級, 最高學習上限200
//            "sword"    : ({40,2,50}),
//            "makefood" : ({40,2,50}),
//        ]) );
//
// 4. 如果想讓此工會導師只有單純的只是讓玩家學習技能, 而沒有加入工會的功
//    能的話, 請加入下列設定至程式中:
//        set("no_join", 1);
//    特別提醒: 如果設 set("no_join",1) 的話, 任何人都可以學此導師的技能
//              喔!!
//
// 5. 如果此工會導師有加入工會的功能, 在玩家成功加入工會的時候, 工會導師
//    會發出訊息給全部的玩家看到, 如果要使用預設值就不必再加入其它參數; 
//    但是, 如果想要自己寫較有創意的訊息的話, 本繼承檔允許你加入最多三個
//    訊息, 以取代原預設值, 方法如下:
//    set("msg_guildclass0","訊息內容");
//    set("msg_guildclass1","訊息內容");
//    set("msg_guildclass2","訊息內容");
//    至少要有 msg_guildclass0  的設定, 接下來的兩個可有可無, 完全按照你
//    的需要, 值得一提的是訊息內容, 訊息內容如果有以 $  為開頭的字, 本繼
//    承檔會用適當的字串來取代之, 請看以下說明:
//    $N	: 加入工會者的名字
//    $n	: 工會導師的名字
//    $c	: 工會名稱(中文)
//    目前只有三種字串可以取代, 如果需要更多的取代字串請通知 Shengsan 
//
// 6. 如果要看參考範例請 more /u/s/shengsan/guild/bluemaster.c
//
// 7. 版本 V1.01.05 新功能:
//    a. 如果 no_join 有設非 0 的值, 任何人都可以學此導師身上的技能
//    b. 可以有條件的讓玩家加入工會, 用法如下:
//       1. 不要加入 set("no_join",1);
//       2. 加入限制條件:
//          set("jointerm","條件字句");
//          條件子句為: xx>數值    或    xx=數值    或    xx<數值
//          如果條件成立就給予 join
//       3. 如果條件不符, 你可以自訂要顯示的內容, 或用預設值也行.
//          自訂的方法:
//          set("jointerm_msg","訊息內容");
//       4. 請參考範例 /u/s/shengsan/guild/bluemaster.c
//
// 8. 版本 V1.03.00 新增功能:
//    a. 增加法術(spell)列表
//    b. 向導師學習技能或法術要給錢
//
// 9. V1.04.00 之後不再限制名稱為工會...職業系統以組織為主...新增加了
//    do_guild_join_with_no_message() 函式...這個函式只是把以前
//    do_guild_join() 裡的訊息部分去掉改為傳回一個適當的數值...
//    傳回值的意義如下:
//     1: 成功	0: 導師的程式寫錯
//    -1: 玩家已經加入其他組織
//    -2: 玩家已經加入了與導師同級或更高級的組織
//    -3: 玩家目前的組織並不適合加入本組織
//    -4: 玩家等級不夠
//    -5: 玩家的 termstr 並沒有大於 termnum 值
//    -6: 玩家的 termstr 並沒有等於 termnum 值
//    -7: 玩家的 termstr 並沒有小於 termnum 值
//    -8: 玩家輸入的組織錯誤或沒有輸入要加入的組織名
//    一樣...範例寫在 /u/s/shengsan/npc/bluemaster.c
//
#include <dbase.h>
#include <mudlib.h>
#include <ansi.h>

string sol_class(object ob, int adv);
void guild_shout(object ob, object me, string msg);
int exp_count(int base,int degree);
int guildgift_count(int ppllv,int value);
int total_guildgift(int *guildgift);

void create()
{
	seteuid(getuid());
}
int do_advance(object ob, object me, string arg)
{
	int *ppl_guildgift;
	int needexp, maxgift, gift_type;

	if( !me->query("adv_class") && me->query("level") > 2 )
	{
		write("你沒有職業就不能升級或加屬性囉！\n");
		return 1;
//		return notify_fail("你沒有職業還想再升級上去阿？\n");
	}

	if( !arg || arg == "level" )
	{
		if( !me->query("adv_class") && me->query("level") > 2 )
		{
			write("你沒有職業還想再升級上去阿？\n");
			return 1;
//			return notify_fail("你沒有職業還想再升級上去阿？\n");
		}
		if( me->query("adv_class") <= 1 && me->query("level") >= 25 )
		{
			write("你尚未轉職之前，就只能這樣了。\n");
			return 1;
//			return notify_fail("你尚未轉職之前，就只能這樣了。\n");
		}
		if( me->query("level") >= 50 )
		{
			write("你的等級已經到達上限了！\n");
			return 1;
//			return notify_fail("你的等級已經到達上限了！\n");
		}

		needexp = exp_count(me->query("level"),14);	// needexp = ((level+1)*14)^2

		tell_object(me,"needexp= "+needexp+"\n");

		if( me->query("exp") < needexp )
		{
			write("你的經驗值還不夠喔！\n");
			return 1;
//			return notify_fail("你的經驗值還不夠喔！\n");
		}
		me->set("exp",me->query("exp")-needexp);
		me->add("level",1);
		
		tell_object(me,"你將等級提昇至 第"
			+ CHINESE_D->chinese_number(me->query("level")) +"級！\n");
		me->set("heart_modify",1);
		me->heart_beat();
		return 1;
	}
	if( arg == "str" || arg == "con" || arg == "int" || arg == "dex" )
	{
		if(  ( me->query(arg) >= me->query("level")*2 )
		  || ( me->query_total_gift() > me->query("level")*5 + 8 ) )
		{
			write("這個屬性加不上去囉！\n");
			return 1;
//			return notify_fail("這個屬性加不上去囉！\n");
		}

		if( me->query("level")>2 )
		{
			switch(arg)
			{
				case "str" : gift_type = 0; break;
				case "con" : gift_type = 1; break;
				case "int" : gift_type = 2; break;
				case "dex" : gift_type = 3; break;
			}
			ppl_guildgift = me->query("guild_gifts");
			if( total_guildgift(ppl_guildgift) != 20 )
			{
				write("你的集團屬性分配表錯誤，請聯絡線上巫師！\n");
				return 1;
//				return notify_fail("你的集團屬性分配表錯誤，請聯絡線上巫師！\n");
			}
			maxgift = guildgift_count(me->query("level"),ppl_guildgift[gift_type]);
			if( me->query(arg) >= maxgift )
			{
				write("你的"+to_chinese(arg)+"已經到達你的極限了！\n");
				return 1;
//				return notify_fail("你的"+to_chinese(arg)+"已經到達你的極限了！\n");
			}
		}
		needexp = exp_count(me->query(arg),7);	// (needexp = (attribut+1)*7)^2
		if(me->query("exp") < needexp)
		{
			write("你需要 "+needexp+" 點經驗值才能提昇"+to_chinese(arg)+"！\n");
			return 1;
//			return notify_fail("你需要 "+needexp+" 點經驗值才能提昇"+to_chinese(arg)+"！\n");
		}
		me->add("exp",-needexp);
		me->add(arg,1);
		me->set("heart_modify",1);
		me->heart_beat();
		tell_object(me,"你的"+to_chinese(arg)+"提升了。\n");
	}
	else
	{
		write("沒有這種屬性！！\n");
		return 1;
//		return notify_fail("沒有這種屬性！！\n");
	}
	return 1;
}

int exp_count(int base,int degree)
{
	int exp;
	exp = (base+1)*degree;
	exp = exp*exp;	
	return exp;
}

int guildgift_count(int ppllv,int value)	// (ppllv*10+ppllv*wizstr)/10
{
	int gift;
	gift = ppllv*10+ppllv*value;
	gift /= 10;
	return gift;
}

int total_guildgift(int *guildgift)		// 計算屬性分配表總和
{
	int i;
	i = guildgift[0]+guildgift[1]+guildgift[2]+guildgift[3];
	return i;
}

int set_guildgift(object me,int *guildgift)
{
	me->set("guild_gifts",guildgift);
	return 1;
}


int do_skill_list(object ob, object me, string arg)                     
{
        mapping skills;
        mixed cost1;
        string playerclass, guildclass, list, *name;
        int i,cost,level,maxlv,price;

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);

        if( !mapp(skills = ob->query("guild_skills")) )
	{
		write("這位導師沒有技能列表！\n");
		return 1;
	}
        name = keys(skills);
        cost1 = values(skills);

	if( playerclass != guildclass && !ob->query("no_join"))
	{
		if( !me->query("no_check_class") )
		{
			write(HIW"這邊的技能"+to_chinese(guildclass)+"才能查看。\n"NOR);
			return 1;
		}
	}
	list = HIR"\n�摃丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐片綅n"NOR;
	list += HIR"��"HIC"技  能  名  稱                   "HIG"經驗值需求   "HIB"學費需求  "HIY"目前等級 / 最高等級"HIR" �鱋n"NOR;
	list += HIR"�聝丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐片嫹n"NOR;
        for(i=0; i<sizeof(name); i++)
	{
		if(cost1[i][1]<1) cost1[i][1]=2;	// 設定 maxlv 的倍數(為什麼要固定2呢? 不解..)
		maxlv = me->query("level")*cost1[i][1];  // maxlv=level的倍數
		if(maxlv >= cost1[i][2]) maxlv=cost1[i][2];
		level = me->query_skill(name[i],1);
			// 後面那個1(非0) 是表示原來的值,不設原值會除2
		cost =(level*level*cost1[i][0])/30;
		price=(level*level*cost1[i][0])/40;
		list += sprintf("  "HIC"%-34s"HIG"%-9d   "HIB"%-9d      "HIY"%3d / %-3d\n"NOR,
		to_chinese(name[i])+"("+name[i]+")",cost,price,level,maxlv);
	}
        write(list);
        return 1;
}


int do_skill_train(object ob, object me, string argx)
{
	mapping skills,myskl;
	mixed cost1;
	string playerclass, guildclass, list, *name,*skil;
	int i,cost,level,maxlv,value;

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);

	if(!mapp(skills = ob->query("guild_skills")) )
	{
		write("這位導師沒有技能列表！\n");
		return 1;
	}
	if(!argx)
	{
		write(HIC"想訓練啥技能??\n"NOR);
		return 1;
//		return notify_fail(HIC"想訓練啥技能??\n"NOR);
	}
	if( playerclass != guildclass && !ob->query("no_join"))
	{
		write(HIW"這邊是"+to_chinese(guildclass)+"專用的訓練場。\n"NOR);
		return 1;
//		return notify_fail(HIW"這邊是"+to_chinese(guildclass)+"專用的訓練場。\n"NOR);
	}
	if(!ob->query("guild_skills/" +argx) )
	{
		write("看清楚﹗這裡沒那種技能。\n");
		return 1;
//		return notify_fail("看清楚﹗這裡沒那種技能。\n");
	}
	name = keys(skills);
	cost1 = values(skills);
	for(i=0; i<sizeof(name); i++)
	{
	  if(argx==name[i])
	    {
		if(cost1[i][1]<1) cost1[i][1]=2;	// 設定 maxlv 的倍數
	    	maxlv = me->query("level")*cost1[i][1];  // maxlv=level的倍數
		level = me->query_skill(argx,1);
		if(level >= maxlv || level >= cost1[i][2])
		{
			write("你的"+to_chinese(argx)+"已經到這裡的最高級了\n");
			return 1;
//			return notify_fail("你的"+to_chinese(argx)+"已經到這裡的最高級了\n");
		}
		cost =level*level*cost1[i][0]/30;
		if(me->query("exp") < cost)
		{
			write("你經驗不夠了\n");
			return 1;
//			return notify_fail("你經驗不夠了\n");
		}
		value = level*level*cost1[i][0]/40;
		if( me->can_afford(value)!=1 )
		{
			write("你帶的錢不夠喔！\n");
			return 1;
//			return notify_fail("你帶的錢不夠喔！\n");
		}
		if(level >= SKILL_D(argx)->improve_limite(me) )
		{
			write("這個技能你只能學到此等級！\n");
			return 1;
//			return notify_fail("這個技能你只能學到此等級！\n");
		}
		me->receive_money(-value);
		message_vision("$N花了"+F_VENDOR->price_string(value,me->money_type())+"學習"+to_chinese(argx)+"。\n",me);
		me->add_skill(argx);
		me->add("exp",-cost);
	    }
	}
	return 1;
}
/*
 *
 *
 */
int do_spell_list(object ob, object me, string arg)                     
{
        mapping spells;
        mixed cost1;
        string playerclass, guildclass, list, *name;
        int i,cost,level,maxlv,price;

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);

        if( !mapp(spells = ob->query("guild_spells")) )
	{
		write("這位導師沒有法術列表！\n");
		return 1;
	}
        name = keys(spells);
        cost1 = values(spells);
	if( playerclass != guildclass && !ob->query("no_join"))
	{
		if( !me->query("no_check_class") )
		{
			write(HIW"這邊的法術是"+to_chinese(guildclass)+"才能查看。\n"NOR);
			return 1;
//			return notify_fail(HIW"這邊是"+to_chinese(guildclass)+"才能查看。\n"NOR);
		}
	}
	list = HIR"\n�摃丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐片綅n"NOR;
	list += HIR"��"HIC"法  術  名  稱                   "HIG"經驗值需求   "HIB"學費需求  "HIY"目前等級 / 最高等級"HIR" �鱋n"NOR;
	list += HIR"�聝丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐丐片嫹n"NOR;
       for(i=0; i<sizeof(name); i++)
	{
		if(cost1[i][1]<1) cost1[i][1]=2;	// 設定 maxlv 的倍數
		maxlv = me->query("level")*cost1[i][1];  // maxlv=level的倍數
		if(maxlv >= cost1[i][2]) maxlv=cost1[i][2];
		level = me->query_spell(name[i],1);
			// 後面那個1(非0) 是表示原來的值,不設原值會除2
		cost =level*level*cost1[i][0]/30;
		price=(level*level*cost1[i][0])/40;
		list += sprintf("  "HIC"%-34s"HIG"%-9d   "HIB"%-9d      "HIY"%3d / %-3d\n"NOR,
		to_chinese(name[i])+"("+name[i]+")",cost,price,level,maxlv);
	}
        write(list);
        return 1;
}


int do_spell_train(object ob, object me, string argx)
{
	mapping spells,myskl;
	mixed cost1;
	string playerclass, guildclass, list, *name;
	int i,cost,level,maxlv,value;

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);
	if(!mapp(spells = ob->query("guild_spells")) )
	{
		write("這位導師沒有法術列表！\n");
		return 0;
	}
	if(!argx)
	{
		write(HIC"想訓練啥法術??\n"NOR);
		return 1;
//		return notify_fail(HIC"想訓練啥法術??\n"NOR);
	}
	if( playerclass != guildclass && !ob->query("no_join"))
	{
		write(HIW"這邊是"+to_chinese(guildclass)+"專用的訓練場。\n"NOR);
		return 1;
//		return notify_fail(HIW"這邊是"+to_chinese(guildclass)+"專用的訓練場。\n"NOR);
	}
	if(!ob->query("guild_spells/" +argx) )
	{
		write("看清楚﹗這裡沒那種法術。\n");
		return 1;
//		return notify_fail("看清楚﹗這裡沒那種法術。\n");
	}
	name = keys(spells);
	cost1 = values(spells);
	for(i=0; i<sizeof(name); i++)
	{
	  if(argx==name[i])
	    {
		if(cost1[i][1]<1) cost1[i][1]=2;	// 設定 maxlv 的倍數
	    	maxlv = me->query("level")*cost1[i][1];  // maxlv=level的倍數
		level = me->query_spell(argx,1);
		if(level >= maxlv || level >= cost1[i][2])
		{
			write("你的"+to_chinese(argx)+"已經到這裡的最高級了\n");
			return 1;
//			return notify_fail("你的"+to_chinese(argx)+"已經到這裡的最高級了\n");
		}
		cost =level*level*cost1[i][0]/30;
		if(me->query("exp") < cost)
		{
			write("你經驗不夠了！\n");
			return 1;
//			return notify_fail("你經驗不夠了！\n");
		}
		value = level*level*cost1[i][0]/40;
		if( me->can_afford(value)!=1 )
		{
			write("你帶的錢不夠喔！\n");
			return 1;
//			return notify_fail("你帶的錢不夠喔！\n");
		}
		if(level >= SPELL_D(argx)->improve_limite(me) )
		{
			write("這個法術你只能學到此等級！\n");
			return 1;
//			return notify_fail("這個法術你只能學到此等級！\n");
		}
		me->receive_money(-value);
		message_vision("$N花了"+F_VENDOR->price_string(value,me->money_type())+"學習"+to_chinese(argx)+"。\n",me);
		me->add_spell(argx);
		me->add("exp",-cost);
	    }
	}
	return 1;
}


int do_guild_join(object ob, object me, string arg)
{
	int *master_guildgift;
	int clevel, termnum;
	string playerclass, guildclass, msg, termstr, str;

	if(!ob->query("adv_class"))
	{
		write("這個NPC並沒有轉職等級記錄，請通知巫師為你解決。\n");
		return 0;
	}
	if(!me->query("adv_class"))
	{
//		write("你並沒有轉職等級記錄，請通知巫師為你解決。\n");
//		return 0;
		me->set("adv_class",0);
	}

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);

	master_guildgift = ob->query("guild_gifts");
	if( total_guildgift(master_guildgift) != 20 )
	{
		write("這位導師的屬性分配表錯誤，請聯絡線上巫師！\n");
		return 1;
	}
	
	switch(ob->query("adv_class")) {
	    case 1   : clevel = 1;  break;
	    default  : clevel = 25; break;
	}


	if( arg && arg == guildclass )
	{
	    if( playerclass == guildclass )
	    {
		write(HIY"你已經加入"+to_chinese(guildclass)+"其他組織了！\n"NOR);
		return 1;
//		return notify_fail(HIY"你已經加入"+to_chinese(guildclass)+"其他組織了！\n"NOR);
	    }
	    if( me->query("adv_class") >= ob->query("adv_class")
	    && playerclass != guildclass)
	    {
		write(HIY"抱歉，你已經加入與我們同級或更高級的"+to_chinese(playerclass)+"組織了！\n"NOR);
		return 1;
//		return notify_fail(HIY"抱歉，你已經加入與我們同級或更高級的"+to_chinese(playerclass)+"組織了！\n"NOR);
	    }
	    if( playerclass != sol_class(ob,ob->query("adv_class")-1)
		&& me->query("adv_class")!=0 )
	    {
		write(HIY"只有"
                      +to_chinese(sol_class(ob,ob->query("adv_class")-1))
                      +"能加入"+to_chinese(guildclass)+"！\n"NOR);
		return 1;
//	        return notify_fail(HIY"只有"
//                      +to_chinese(sol_class(ob,ob->query("adv_class")-1))
//                      +"能加入"+to_chinese(guildclass)+"！\n"NOR);
	    }
	    if( me->query("level") < clevel)
	    {
		write(HIY"以你目前的等級並不能在組織內轉職，請你升到"
	              +clevel+"級後再來吧！\n"NOR);
		return 1;
//		return notify_fail(HIY"以你目前的等級並不能在組織內轉職，請你升到"
//	              +clevel+"級後再來吧！\n"NOR);
	    }
	    // 
	    if( !ob->query("no_join") && ob->query("jointerm") )
	    {
	        if( sscanf(ob->query("jointerm"),"%s>%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)<=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				write(HIY"你的"+termstr+"值不足以加入本組織喔！\n"NOR);
				return 1;
//				return notify_fail(HIY"你的"+termstr+"值不足以加入本組織喔！\n"NOR);
			 }
	        }
	        else if( sscanf(ob->query("jointerm"),"%s=%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)!=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				write(HIY"你的"+termstr+"值不足以加入本組織喔！\n"NOR);
				return 1;
//				return notify_fail(HIY"你的"+termstr+"值不足以加入本組織喔！\n"NOR);
			 }
	        }
	        else if( sscanf(ob->query("jointerm"),"%s<%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)>=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				write(HIY"你的"+termstr+"值不足以加入本組織喔！\n"NOR);
				return 1;
//				return notify_fail(HIY"你的"+termstr+"值不足以加入本組織喔！\n"NOR);
			 }
	        }
	        else { write(HIY"此工會導師的程式語法錯誤！\n"NOR); return 1; }
	    }

	    me->set("adv_class",ob->query("adv_class"));

	    switch(ob->query("adv_class")) {
	        case 1 : me->set("class1",guildclass);
			 set_guildgift(me,master_guildgift);// 只有在加入第一級集團才有設定屬性分配表
			 break;
	        case 2 : me->set("class2",guildclass); break;
	        default  :
	    }

	    if( !stringp(msg = ob->query("msg_guildclass0")) )
	    {
	        shout("\n"
		    HIW"歡迎"+me->query("name")+"加入"+to_chinese(guildclass)+"組織﹗﹗﹗\n"NOR
		    HIC"從今日起，"+me->query("name")+"即是"+to_chinese(guildclass)+"組織的一份子。\n"NOR
		    HIC"希望你以後能名揚天下...替我們"+to_chinese(guildclass)+"組織爭光。\n"NOR,me);
	        message("msg",
		    HIW"歡迎"+me->query("name")+"加入"+to_chinese(guildclass)+"組織﹗﹗﹗\n"NOR
		    HIC"從今日起，"+me->query("name")+"即是"+to_chinese(guildclass)+"組織的一份子。\n"NOR
		    HIC"希望你以後能名揚天下...替我們"+to_chinese(guildclass)+"組織爭光。\n"NOR,me);
	    }
	    else
	    {
	        guild_shout(ob,me,msg);
	        if( stringp(msg = ob->query("msg_guildclass1")) )
		    guild_shout(ob,me,msg);
	        if( stringp(msg = ob->query("msg_guildclass2")) )
		    guild_shout(ob,me,msg);
	        msg = "\n";
	        guild_shout(ob,me,msg);
	    }

	}
	else
	{
		write(HIY"你到底要加入組織嗎？看清楚我是"+to_chinese(guildclass)+"耶！\n"+NOR
	              +HIM+"如果要加入我們的話請 join "+guildclass+"。\n"NOR);
	}

        return 1;
}

int do_guild_join_with_no_message(object ob, object me, string arg)
{
	int *master_guildgift;
	int clevel, termnum;
	string playerclass, guildclass, msg, termstr, str;

	if(!ob->query("adv_class"))
	{
		write("這個NPC並沒有轉職等級記錄，請通知巫師為你解決。\n");
		return 0;
	}
	if(!me->query("adv_class"))
	{
//		write("你並沒有轉職等級記錄，請通知巫師為你解決。\n");
//		return 0;
		me->set("adv_class",0);
	}

	guildclass = sol_class(ob,0);
	playerclass= sol_class(me,0);

	master_guildgift = ob->query("guild_gifts");
	if( total_guildgift(master_guildgift) != 20 )
	{
		write("這位導師的屬性分配表錯誤，請聯絡線上巫師！\n");
		return 0;
	}


	switch(ob->query("adv_class")) {
	    case 1   : clevel = 1;  break;
	    default  : clevel = 25; break;
	}


	if( arg && arg == guildclass )
	{
	    if( playerclass == guildclass )
	    {
		// 玩家已經加入其他組織
		return -1;
	    }
	    if( me->query("adv_class") >= ob->query("adv_class")
	    && playerclass != guildclass)
	    {
		// 玩家已經加入了與導師同級或更高級的組織
		return -2;
	    }
	    if( playerclass != sol_class(ob,ob->query("adv_class")-1)
		&& me->query("adv_class")!=0 )
	    {
		// 玩家目前所加入的組織並不是該組織認可的組織
		// 也就是說他目前的組織並不適合加入該組織
	        return -3;
	    }
	    if( me->query("level") < clevel)
	    {
		// 玩家等級不夠
		return -4;
	    }
	    // 
	    if( !ob->query("no_join") && ob->query("jointerm") )
	    {
	        if( sscanf(ob->query("jointerm"),"%s>%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)<=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				// 玩家的 termstr 並沒有大於 termnum 值
				return -5;
			 }
	        }
	        else if( sscanf(ob->query("jointerm"),"%s=%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)!=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				// 玩家的 termstr 並沒有等於 termnum 值
				return -6;
			 }
	        }
	        else if( sscanf(ob->query("jointerm"),"%s<%d", termstr, termnum)==2 )
	        {
	            if(me->query(termstr)>=termnum)
	                 if( stringp(msg = ob->query("jointerm_msg")) )
		             { message("guild_nojoin", msg, me); return 1; }
	                 else
			 {
				// 玩家的 termstr 並沒有小於 termnum 值
				return -7;
			 }
	        }
	        else { write(HIY"此工會導師的程式語法錯誤！\n"NOR); return 0; }
	    }

	    me->set("adv_class",ob->query("adv_class"));

	    switch(ob->query("adv_class")) {
	        case 1 : me->set("class1",guildclass);
			 set_guildgift(me,master_guildgift);// 只有在加入第一級集團才有設定屬性分配表
			 break;
	        case 2 : me->set("class2",guildclass); break;
	        default  :
	    }

	}
	else
	{
		// 玩家輸入的組織錯誤或沒有輸入要加入的組織名
		return -8;
//		write(HIY"你到底要加入工會嗎？看清楚我是"+to_chinese(guildclass)+"耶！\n"+NOR
//	              +HIM+"如果要加入我們的話請 join "+guildclass+"。\n"NOR);
	}

        return 1;
}

string sol_class(object ob, int adv)
{
	string guildclass;
	
	if( adv > ob->query("adv_class") )
	    return "";
	if(!ob->query("adv_class"))
	    return "";
	if((ob->query("adv_class") == 1 && !adv) || adv == 1)
	    return guildclass = ob->query("class1");
	if((ob->query("adv_class") == 2 && !adv) || adv == 2)
	    return guildclass = ob->query("class2");
	return "";
}

void guild_shout(object ob, object me, string msg)
{
	string my_name, master_name, master_class;
	string str1;

	my_name      = me->query("name");
	master_name  = ob->query("name");
	master_class = to_chinese(sol_class(ob,0));

	// N: 自己的名字 n: 導師的名字 c: 導師的職業
	str1 = replace_string(msg,  "$N", my_name);
	str1 = replace_string(str1, "$n", master_name);
	str1 = replace_string(str1, "$c", master_class);

	message("guild_shout", str1, users(), me);
	message("guild_shout", str1, me);

}