// sacrifice
#include <ansi.h>
inherit F_FINANCE;
inherit F_VENDOR;
inherit F_CLEAN_UP;
int do_sac(object me,object ob,int world);
void create() { seteuid(getuid()); }
int main(object me, string str)
{
        object ob,*obs;
        int j,k,time;
        string name;
        if(!str) return notify_fail("你要奉獻什麼東西給天神?\n");
        time = me->money_type();
        if(str == "all")
        {
          obs = all_inventory(environment(me));
          k=sizeof(obs);
          if( k > 0)
          {
                if( k > 10 ) k=10;
                
                for(j=0; j<k; j++)
                {
                        //if( obs[j]->is_character() ) continue;
                        if(!obs[j]) continue;
                        if(obs[j]->query("money_id")) continue;
                        if(living(obs[j])) continue;
                        if(obs[j]->is_corpse() && obs[j]->query("owner_id")) continue;
                        if(obs[j]->query("no_sac") || obs[j]->query("no_get") || obs[j]->query("no_get") ) continue;
                        do_sac(me,obs[j],time);
                }
          }
          return 1;
        }
        
        ob=present(str,environment(me));
        if(!ob) return notify_fail("這個地方並沒有這項物品。\n");
        if(ob==me)
        {
                message_vision("$N想將自己奉獻給天神，但是好像沒人理睬。\n",me);
                return 1;
        }
        name=ob->name();
        if(ob->query("money_id")) return notify_fail("天神是不接受金錢的。\n");
        if(ob->is_corpse() && stringp(ob->query("owner_id")))
                return notify_fail("你不能奉獻玩家的屍體給天神。\n");
        if(ob->query("no_sac") || ob->query("no_get") || ob->query("board_id") )
                return notify_fail("這個"+name+"無法奉獻。\n");
        if(living(ob)) return notify_fail("除非"+name+"死了，否則別想!\n");
        if(ob->query("equipped")) return notify_fail("你必需先將"+name+"解除裝備。\n");
        
        return do_sac(me,ob,time);
}

int do_sac(object me,object ob,int world)
{
        object *inv;
        int money,i;
        string obname;
        money = ob->query("value")/10;
        if(money < 1 ) money = 1;

        obname=ob->short();

        message_vision("$N將"+obname+"奉獻給大地。\n",me);
        me->add("bank/past", money);            
        write("你得到" + price_string(money, me->money_type())+"作為獎賞。\n");

        if(ob->query_max_encumbrance()) //for corpse
        {
                inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(!inv[i]) continue;
                        if(inv[i]->query("equipped")) inv[i]->unequip();
                        if( !inv[i]->query("no_drop") && !inv[i]->query("no_put") ) inv[i]->move(environment(ob));
                }
        }
        
        destruct(ob);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: sac <item>

當你有過多或不需要的物品，可以將它奉獻給天神。
你可以獲得奉獻物價值的10%，做為獎勵。

HELP
);
        return 1;
}

