#include <ansi.h>

// 獎勵
private void do_bonus(object room)
{
        object *obs;
        string msg;
         int i, chance;

        obs = all_inventory(room);
        if (sizeof(obs) < 1) {
                message("world:world1:vision",HIM"【謠言】"+"龍井棧道"HIY"明月皎皎"HIM"，美景非凡，無數遊人讚嘆不已。\n"NOR,users());
                return;
        }
        
          if( random(100) < 20) {
                msg =  HBK "\n\t只見暮雲層層，明月遲遲無法露臉。\n" NOR;
                msg += HIG "\n\t你不禁嘆息道：「太可惜了...」\n" NOR;
                tell_object(room, msg);
                return;
        }
        chance = sizeof(obs);
        if(chance > 20) chance = 20;

        msg = HIW "\n\t快上西樓，怕天放、浮雲遮月。但喚取、玉纖橫笛，一聲吹裂。\n"
                   "\t誰做冰壺浮世界，最憐玉斧修時節。問嫦娥、孤冷有愁無，應華髮。\n"
                   "\t若得長圓如此夜，人情未必看承別。把從前、離恨總成歡，歸時說。\n";

        if( chance < random(365)) {
               msg += HIM "\n\n\t明月未出群山高，瑞光千丈生白毫。\n" NOR;
               msg += HIM "\t一杯未盡銀闕涌，亂雲脫壞如崩濤。\n" NOR;
               msg += HIG "\n\t皎潔明月發出光輝，你心靈上的掛礙全都消除，在武藝上的修為又更上一層樓了。\n\n" NOR;
               for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 10 + random(5) );
                                        obs[i]->add("war_art", 10 + random(5) );
                                        obs[i]->add("exp", 25000 + random(20000) );
                }

        } else {
                 msg += HIG "\n\t你望著皎潔的明月，心中若有所悟，在武藝上的修為稍有進展了。\n\n" NOR;
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 3 + random(2) );
                                        obs[i]->add("war_art", 3 + random(2) );
                                        obs[i]->add("exp", 20000 + random(5000) );
                }

        }

        tell_object(room, msg);
        message("world:world1:vision",HIM"【謠言】"+"龍井棧道"HIY"明月皎皎"HIM"，美景非凡，無數遊人讚嘆不已。\n"NOR,users());
}

// 事件觸發
void trigger_event()
{
        object room;

        if (objectp(room = find_object("/open/world1/faceoff/sky/moon")))
                do_bonus(room);
                
}

void create() 
{ 
        seteuid(getuid()); 
}

