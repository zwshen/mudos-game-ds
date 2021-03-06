#include <ansi.h>

inherit ROOM;

string *gamble_msg = ({
  HIC+"莊家把三顆骰子倒在大盅裡....\n"+NOR,
  HIC+"莊家拿起了大盅急速的搖動起來了....\n"+NOR,
  HIC+"莊家大喊著, 本局開始了, 快下注唷！！\n"+NOR,
  HIC+"莊家大喊著, 下好離手, 下好離手！！\n"+NOR,  
  ""
});

string *bet_item = ({
});

string *dict = ({
        "╭───╮", 
        "│      │",
        "│●    │",
        "│  ●  │",
        "│    ●│",
        "│●  ●│",
        "╰───╯",
        "│  "+HIR+"●"+NOR+"  │",
});

string drawdict(int x,int y,int z);
int run_gamble(int stage);
int pay_gamble();

void create()
{
        set("short", "十賭九贏賭坊");
        set("long", @LONG
這是一間非常喧嘩的賭坊，屋內擺設了九張賭桌，皆圍滿了人，擠地
水洩不通，且只四面牆堵只開了幾扇小窗戶，空氣顯得十分鬱悶。西面牆
上貼了張紙張，上頭似乎寫著一些規定和賭法。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "north" : __DIR__"wynd2",
          "south": __DIR__"mjroom",
        ]));
        set("item_desc",([
        "紙張" : @LONG
  【十賭九贏賭坊】

下注：
	bet <號碼||same> <數量>
查看：check

本賭坊每次皆擲三粒骰子，可任意下注

	１∼６等六個號碼(賠率: 一賠一)。
	same 豹子(賠率: 一賠三十)。
LONG
        ]) );

	set("objects",([
		__DIR__"npc/ringman": 2,
	]) );

        set("no_clean_up", 0);
	set("no_fight",0);
        set("light",1);
        setup();
}

void setup()
{
        ::setup();
        call_out("run_gamble",15,0);
        return;
}

void init()
{
	  add_action("do_bet","bet");
	  add_action("do_check","check");
}

int run_gamble(int stage)
{
	if( stage < sizeof(gamble_msg) )
        {
	        tell_room(this_object(),gamble_msg[stage]);
	        stage += 1;

	        if(query("count") < 4 ) add("count",1); 
		else set("count",0);

	        call_out( "run_gamble",15,stage);
	}
	if( stage == sizeof(gamble_msg)-1) 
		call_out("pay_gamble",5);
        return 1;
}

int pay_gamble()
{
        object *inv;
         int i,x,y,z, money,flag;

        inv = all_inventory(this_object());

                       x = random(6)+1;
    		y = random(6)+1;
	       	z = random(6)+1;
			if ((x==y) && (y==z) && (z==x))
			{
        		x = random(6)+1;
        		y = random(6)+1;
	        	z = random(6)+1;
	        	if ((x==y) && (y==z) && (z==x))
				{
        			x = random(6)+1;
        			y = random(6)+1;
	        		z = random(6)+1;
				}
			}
	
        drawdict(x,y,z);
        tell_room(this_object(),"莊家喝道：『開！！ "+x+"、"+y+"、"+z+"！！』\n");
        tell_room(this_object(),drawdict(x,y,z));
        if(x==y && y==z) tell_room(this_object(),"莊家說道：『嘖..居然是豹\子！！照慣例單號賠率加倍...』\n");
        flag = 0;

	for(i=0; i<sizeof(inv); i++) 
	{
            if( !inv[i]->query_temp("gamblebet") || 
	  (inv[i]->query_temp("gamblebet/1") + inv[i]->query_temp("gamblebet/2") +
               inv[i]->query_temp("gamblebet/3") + inv[i]->query_temp("gamblebet/4") +
               inv[i]->query_temp("gamblebet/5") + inv[i]->query_temp("gamblebet/6") +
               inv[i]->query_temp("gamblebet/7")
	    < 1 )  )  continue;
        money = 0;

	if(inv[i]->query_temp("gamblebet/"+x) > 0)
                money += inv[i]->query_temp("gamblebet/"+x)*2;
        if(inv[i]->query_temp("gamblebet/"+y) > 0)
                money += inv[i]->query_temp("gamblebet/"+y)*2;
        if(inv[i]->query_temp("gamblebet/"+z) > 0)
                money += inv[i]->query_temp("gamblebet/"+z)*2;        
        if( x == y && x == z )
        {
        	money *= 2;
        	if(inv[i]->query_temp("gamblebet/7") > 0)
        		money += inv[i]->query_temp("gamblebet/7")*30;
        }


        if( money > 0 ) 
	{
        flag = 1;

        if( x != y || x != z || y != z )
	{
	        if( inv[i]->query_temp("gamblebet/"+x) > 0 )
		        tell_room(this_object(),  "莊家說道："+HIY "「"+inv[i]->query("name")+"押中了 "+x+" 號！」\n"+NOR);
	        if( inv[i]->query_temp("gamblebet/"+y) > 0 )
		        tell_room(this_object(),  "莊家說道："+HIY "「"+inv[i]->query("name")+"押中了 "+y+" 號！」\n"+NOR);
	        if( inv[i]->query_temp("gamblebet/"+z) > 0 )
			tell_room(this_object(),  "莊家說道："+HIY "「" +inv[i]->query("name")+"押中了 "+z+" 號！」\n"+NOR);
        } 
	else
	{
            if(inv[i]->query_temp("gamblebet/7"))
              tell_room(this_object(),
		 "莊家臉色慘綠的說道："HIW+"「"+inv[i]->query("name")+"中了三星 ["+x+"]！！」\n"+NOR);
	}

         message_vision("$N本局贏了"+money+"枚古幣！！\n", inv[i] );
          inv[i]->add("bank/past", money);
	}
	 else
	{	
		 tell_object(inv[i],"你不幸槓龜了。\n");
	         //改成BET時付錢    inv[i]->receive_money(-total);
	}
        inv[i]->delete_temp("gamblebet");
        inv[i]->delete_temp("gamblebet_count");
	}

        if( !flag )
		tell_room(this_object(),"莊家大喊一聲：「通殺！！」，神色間非常高興。\n" );
	
        call_out("run_gamble",5,0);
}

int do_bet(string str)
{

        int number, amount, i,count;
          string *terms;
          object me;
        mapping bets;
        
        me = this_player();
        if( query("count") != 3) return notify_fail("本局還沒開始。\n");
        if( !str ) return notify_fail("用法 bet <號碼|same> <數量>\n");
        if( sscanf(str, "same %d ", amount)==1 )
        {
                number = 7;
        }
        else if( !str || sscanf(str, "%d %d", number, amount)==2)
        {
                if( !number || number > 6 || number < 1)
                        return notify_fail("一粒骰子那有這樣的點數？\n");
        } else return notify_fail("用法 bet <號碼|same> <數量>\n");

         if( amount > 1000000)
                return notify_fail("本賭坊不接受這種大賭注。\n");
        if( amount < 0 ) 
                return notify_fail("唉呀呀....銀兩那有負的丫。\n");
         if( amount > me->query("bank/past") ) 
                return notify_fail("你銀行的存款不夠。\n");

        bets = me->query_temp("gamblebet");
        count= me->query_temp("gamblebet_count"); //luky 限制次數.. (原先有重複壓同一個就不限制的bug.
        if (count>2)  return notify_fail("你一局之中最多只能壓三次。\n");
        if( me->query_temp("gamblebet") )
        {
                bets = me->query_temp("gamblebet");
                terms = keys(bets);
        }
        else
        {
                 for( i=0; i<sizeof(bet_item)+1; i++) 
                        me->set_temp("gamblebet/"+i, 0);
        }
      if(number!=7) 
        message_vision("$N這局在"+number+"號下注了"+amount+"枚古幣。\n", me);
      else 
        message_vision("$N這局在[豹\子]下注了"+amount+"枚古幣。\n", me);

        // 直接用銀行扣款
        me->add("bank/past",-amount);
        me->add_temp("gamblebet_count",1);//luky
        me->add_temp("gamblebet/"+number,amount );
        return 1;
}


int do_check()
{
	object me;

	me=this_player();

	if( me->query_temp("gamblebet") )
	{
	tell_object(me,HIY "你目前下注的情形是：\n" NOR );
	
	if( me->query_temp("gamblebet/1") )
		tell_object(me,HIY "【１】號： "+me->query_temp("gamblebet/1")+"枚古幣\n"NOR );
	if( me->query_temp("gamblebet/2") )
		tell_object(me,HIY "【２】號： "+me->query_temp("gamblebet/2")+"枚古幣\n"NOR );
	if( me->query_temp("gamblebet/3") )
		tell_object(me,HIY "【３】號： "+me->query_temp("gamblebet/3")+"枚古幣\n"NOR );
	if( me->query_temp("gamblebet/4") )
		tell_object(me,HIY "【４】號： "+me->query_temp("gamblebet/4")+"枚古幣\n"NOR );
	if( me->query_temp("gamblebet/5") )
		tell_object(me,HIY "【５】號： "+me->query_temp("gamblebet/5")+"枚古幣\n"NOR );
	if( me->query_temp("gamblebet/6") )
		tell_object(me,HIY "【６】號： "+me->query_temp("gamblebet/6")+"枚古幣\n"NOR );
	if( me->query_temp("gamblebet/7") )
		tell_object(me,HIY "【豹\子】： "+me->query_temp("gamblebet/7")+"枚古幣\n"NOR );
	}
	else
		return notify_fail("你目前並沒有任何下注。\n");
	return 1;	
}               

string paint1(int x)
{
   switch(x) {
                case 1 : return dict[1];
                case 2 : return dict[2];
                case 3 : return dict[4];
                case 4 : return dict[5];
                case 5 : return dict[5];
                case 6 : return dict[5];
                default : return dict[1];
        }               
}

string paint2(int x)
{
        switch(x) {
                case 1 : return dict[7];
                case 2 : return dict[1];
                case 3 : return dict[3];
                case 4 : return dict[1];
                case 5 : return dict[3];
                case 6 : return dict[5];
                default : return dict[1];
        }               
}
string paint3(int x)
{
        switch(x) {
                case 1 : return dict[1];
                case 2 : return dict[4];
                case 3 : return dict[2];
                case 4 : return dict[5];
                case 5 : return dict[5];
                case 6 : return dict[5];
                default : return dict[1];
        }               
}

string drawdict(int x,int y,int z)
{
        string dicts;
        
        dicts = "\n";
        dicts += "      "+dict[0]+"      "+dict[0]+"      "+dict[0]+"\n";
        dicts += "      "+paint1(x)+"      "+paint1(y)+"      "+paint1(z)+"\n";
        dicts += "      "+paint2(x)+"      "+paint2(y)+"      "+paint2(z)+"\n";
        dicts += "      "+paint3(x)+"      "+paint3(y)+"      "+paint3(z)+"\n";
        dicts += "      "+dict[6]+"      "+dict[6]+"      "+dict[6]+"\n\n";
        return dicts;
}

