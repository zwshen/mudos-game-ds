//標準摸彩商人繼承檔    - by Luky -
// V2.0 by Tmr 2007/01/24
// 改成「四星彩」的玩法

#include <dbase.h>
#include <ansi.h>
inherit F_VENDOR;
string args;

void create()
{
    seteuid(getuid());
}

string item_desc(object ob)
{
    if(ob->is_ticket()) return HIC+"彩卷"+NOR;
    else if(ob->query("skill_type")) return HIG+"武器"+NOR;
    else if(ob->query("armor_type")) return HIY+"防具"+NOR;
    else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap")) return HIC+"回復"+NOR;
    else if(ob->is_food()) return HIM"食物"NOR; // by shengsan
    else return "道具";
}

string item_list(object ob)
{
    return sprintf("%8d .............. %4s  %-26s",
                   ob->query("value"),item_desc(ob),ob->short()
                  );
}

int do_list(string arg)
{
    object goods,me;
    mapping item;
    string list, *file;
    int i,*supply_cost,debug;

    me=this_player();

    if(wizardp(me) && me->query("env/debug")) debug=1;
    else debug=0;

    if(!mapp(item = query("sell_list")) )
    {
        write("這位獎卷商人沒有物品列表！\n");
        return 0;
    }
    file =  keys(item);
    supply_cost = values(item);
    list = "\n\n┌───────────────────────────┐\n";
    list +="│ 價 錢                種類  目前可以購買的貨品清單    │\n";
    list +="└───────────────────────────┘\n";
    for(i=0; i<sizeof(file); i++)
    {
        goods = load_object(file[i]);
        if(goods)
        {
            list+= item_list(goods);
            if(goods->is_ticket() && !LOTTERY_D->can_buy_ticket()) list+= "<已售完>";
            if(debug) list+= sprintf(GRN+" SP:(%3d)\n"+NOR,supply_cost[i]);
            else list+="\n";
        }
    }
    list +="\n";
    if(i==0) return notify_fail(this_object()->query("name")+"對你說: 對不起唷..貨都賣完了。\n");
    else me->start_more(list);
    return 1;
}

int do_buy(string arg)
{
     int amount,valus,i,j,*supply_cost,world;
    object goods,ob,me;
    string item,*file;
    mapping items;

    me = this_player();
    if(!arg) return notify_fail("你要買什麼東西？\n");

    if(sscanf(arg,"%d %s",amount,item)!=2)
    {
        amount=1;
        item = arg;
        if(item == "ticket")
        {
            // 取得一個四星彩
            amount = LOTTERY_D->find_ticket_num();
        }
    }

    if(!mapp(items = query("sell_list")) )
    {
        write("這位小販沒有物品列表！\n");
        return 0;
    }


    file =  keys(items);
    supply_cost = values(items);
    for(i=0; i<sizeof(file); i++)
    {
        goods = load_object(file[i]);
        if(goods)
        {
            if(goods->id(item))
            {
                if(goods->is_ticket())
                {
                    if(!me->can_afford(goods->query("value")))
                        return notify_fail("你身上的錢不夠。\n");
                    if( (goods->query_weight()+me->query_encumbrance())>me->query_max_encumbrance() )
                        return notify_fail("你拿不動這麼多東西。\n");
                    if( (int)me->query_capacity() + (int)goods->query("volume") > (int)me->query_max_capacity() )
                        return notify_fail("你身上放不下這麼多東西。\n");
                    if( me->query("supply_point") < supply_cost[i])
                        return notify_fail(this_object()->query("name")+"對你說: 你已經買了不少東西了..還是等過一會兒再來買吧.. 。\n");
                    if( amount < 0 || amount > LOTTERY_D->query_max_ticket() ) return notify_fail("沒有這個號碼喔。\n");
                    //                    if(!LOTTERY_D->can_buy_ticket()) return notify_fail("本期彩卷已經全部賣完了。\n");
                    //                  if(!LOTTERY_D->add_ticket_number(amount)) return notify_fail((string)amount+"號的彩卷已經賣掉了。\n");

                    valus=goods->query("value");
                    me->receive_money(-valus);
                    me->add("supply_point",-supply_cost[i]);
                    message_vision("$N花了"+price_string(valus,me->money_type())+"向$n買了一張"+
                                   amount+"號的"+goods->name()+"。\n",me,this_object());
                    ob = LOTTERY_D->createTicket();
                    ob->set("number",amount);
                    if(me->query_encumbrance() + ob->weight() > (int)me->query_max_encumbrance()) ob->move(environment(me));
                    else ob->move(me);

                    me->save();
                    return 1;
                }
                else
                {

                    if(!me->can_afford(goods->query("value")*amount))
                        return notify_fail("你身上的錢不夠。\n");
                    if( (goods->query_weight()*amount+me->query_encumbrance())>me->query_max_encumbrance() )
                        return notify_fail("你拿不動這麼多東西。\n");
                    if( me->query("supply_point") < supply_cost[i]*amount)
                        return notify_fail(this_object()->query("name")+"對你說: 你已經買了不少東西了..還是等過一會兒再來買吧.. 。\n");
                    if( amount < 1 ) return notify_fail("至少要買一個吧。\n");
                    valus=goods->query("value")*amount;
                    me->receive_money(-valus);
                    me->add("supply_point",-supply_cost[i]*amount);
                    world = me->money_type();
                    message_vision("$N花了"+price_string(valus,me->money_type())+"向$n買了"+
                                   chinese_number(amount)+goods->query("unit")+goods->name()+"。\n",me,this_object());

                    for(j=0;j<amount;j++)
                    {
                        ob = new(file[i]);
                        if(ob->is_character()) ob->move(environment(me));
                        else    ob->move(me);
                        me->save();
                    }
                    return 1;
                }
            }
        }
    }

    return notify_fail(this_object()->query("name")+"沒有賣這種東西。\n");

}

int do_reward(string arg)
{
    string msg;
    object *ticket,me,gift;
    int i,k=0,exp,flag,check, na,nb;
    int pop;

      string where,str="";
    me = this_player();
    ticket=all_inventory(me);
    if(sizeof(ticket)<1)
        return notify_fail("你並沒有彩卷可以對獎。\n");
    //  if(sizeof(ticket)>50)
    //        return notify_fail("你身上的彩卷大於50張，請減少一些再來兌獎。\n");

    switch(me->money_type())
    {
    case 1: where="bank/past"; break;
    case 2: where="bank/now"; break;
    case 3: where="bank/future"; break;
    default: where="bank/past"; break;
    }

    flag = 0;
    for(i=0;i<sizeof(ticket);i++)
    {
         if(!ticket[i]->is_ticket() ) continue;
        k++;
        if(k==1) {
            //          str+="$N拿了一些彩卷給$n。\n$n細心地一張張翻看著。\n";
            message_vision("$N拿了一些彩卷給$n。\n$n細心地一張張翻看著。\n", me, this_object());
        }
        check = LOTTERY_D->query_lottery(ticket[i]->query("number"),ticket[i]->query("time"));

        switch(check)
        {
        case -2:
            //        str+=YEL"$n搖搖頭說: 這張彩卷現在不可以對獎喔。\n"NOR;
            message_vision(YEL"$n搖搖頭說: 這張彩卷現在不可以對獎喔。\n"NOR, me, this_object());
            break;
        case -1:
            //message_vision(YEL"$N搖搖頭說: 這張彩卷已經過期了喔。\n"NOR"$N用力把彩卷給撕掉了。\n",this_object());
            destruct(ticket[i]);
            break;
        case 0:
            //message_vision(YEL"$N搖搖頭說: 這張彩卷並沒有中獎, 希望你下次的運氣會比較好。\n"NOR"$N用力把彩卷給撕掉了。\n",this_object());
            destruct(ticket[i]);
            break;
        case 99:
            flag++;
            message_vision(YEL"$n嚇了一跳, 斷斷續續的說:"HIC"天哪∼∼  $N...您中了..超...超級大獎！！ \n"NOR, me, this_object());
             msg =  sprintf(HIC"【彩卷中心】幸運的%s(%s)中了第%d期"HIY"超級大獎"HIC"，獎卷編號:%4d。[%8s]\n",me->name(1), me->query("id"), ticket[i]->query("time"),ticket[i]->query("number"), ctime(time())) ;
            message("system", msg ,users());
            RECORD_D->add_temp_record(msg);
            destruct(ticket[i]);
            gift = new("/open/lottery/ankle.c");
            str += "你得到獎品: "+gift->short(1)+"。\n";
            if(!gift->can_move(me)) gift->move(environment(me));
            else gift->move(me);
            break;
        default:
            // 幾A幾b
            na = check / 10;
            nb = check % 10;
            if(na==0 && nb==0) {
                destruct(ticket[i]);
                break;
            }
            flag++;
            if(na + nb == 4) {
                  msg = sprintf(HIC+"【彩卷中心】恭喜%s(%s)幸運的中了第%d期的"HIG"%2d"HIC"A"HIW"%2d"HIC"B獎，獎卷編號:%d。[%s]。\n"NOR,me->name(1), me->query("id"),LOTTERY_D->query_times(),na,nb,ticket[i]->query("number"),ctime(time()));
                message("system", msg ,users());
                RECORD_D->add_temp_record( msg );
            }

            exp = 0;
            if(nb==1) exp = 100;
            if(nb==2) exp = 1000;
            if(nb==3) exp = 20000;
            // 2a2b
            if(na==2 && nb==2) {
                  gift = new("/open/lottery/ankle2.c");
                str += "你得到獎品: "+gift->short(1)+"。\n";
                if(!gift->can_move(me)) gift->move(environment(me));
                else gift->move(me);
            }


            if(nb==4) {
                gift = new("/open/always/doll2.c");
                str += "你得到獎品: "+gift->short(1)+"。\n";
                if(!gift->can_move(me)) gift->move(environment(me));
                else gift->move(me);
            }
            pop = 0; // 聲望
        if(na==1) { exp += 500;}
            if(na==2) { exp += 10000; pop = 2;}
            if(na==3) { exp += 40000; pop = 4;}
            if(na==4) {
                gift = new("/open/always/doll.c");
                str += "你得到獎品: "+gift->short(1)+"。\n";
                if(!gift->can_move(me)) gift->move(environment(me));
                else gift->move(me);
            }

            // 1a3b
            if(na==1 && nb==3) {
                exp += 80000;
                pop += 8;
            }

            if(exp>0) {
                me->add("exp",exp);
                str+="你得到了"+(string)exp+"點經驗值。\n";
            }
            if(pop>0) {
                me->add("popularity",pop);
                str+="你得到了"+(string)pop+"點聲望。\n";
            }

            destruct(ticket[i]);
        }
    }
    if(k<1)     return notify_fail("你並沒有彩卷可以對獎。\n");

    tell_object(me, str );
    if(!flag)
    {
        message_vision("$n拍拍$N的肩膀說: 很可惜, 這些獎卷都沒有中大獎, 希望你下次運氣會好一點。\n", me, this_object());
        return 1;
    }
    message_vision("$n把其他沒中的獎卷處理掉之後, 高興的和$N握手祝賀。\n", me, this_object());
    return 1;
}


int is_lottery_npc()
{
    return 1;
}

