// 天池瀑布
// tmr 2006/11/14

#include <ansi.h>

// 獎勵
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int r,i, chance;

            obs = all_inventory(room);

        if (sizeof(obs) < 1) {
                message("world:world1:vision",HIM"【謠言】"+""HIW"天池瀑布"HIM"激流澎湃，奇景非凡，無數遊人嘆羨不已。\n"NOR,users());
                return;
        }
        chance = sizeof(obs);
        if(chance > 20 ) chance = 20;
          r = random(365);
          if (r < chance )
        {
                msg = HIC "\n\t只聽轟隆隆聲音大做，振聾發聵，令人心懼神搖！你抬頭看去，只見\n";
                msg += HIC "\t黃昏中天池籠罩在層層霧氣之中，分外妖嬈。洞外水流飛瀉，氣勢驚人！\n" NOR;
                  msg += HIW "\n\t日照香爐升紫煙，遙看瀑布挂前川。\n" NOR;
                msg += HIW "\t飛流直下三千尺，疑是銀河落九天。\n" NOR;
                msg += HIG "\n\t你望著湍急的瀑布飛練，為這世間美景驚嘆不已，從中不禁領悟到了武學的道理。\n\n" NOR; 


                // 增加聲望跟戰鬥藝術
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 10 + random(10) );
                                        obs[i]->add("war_art", 10 + random(10) );
                                        obs[i]->add("exp", 50000 + random(50000) );
                    }
                    
                tell_object(room, msg);
               message("world:world1:vision",HIM"【謠言】"+""HIW"天池瀑布"HIM"激流澎湃，奇景非凡，無數遊人嘆羨不已。\n"NOR,users());
          } else  if (r < 180)   {
                msg = HIC "\n\t一陣轟隆轟隆的聲音傳來，你抬頭一看，只見黃昏中瀑布騰起層層霧氣。\n" NOR;
                
                switch (random(3))
                {
                case 0:
                        msg += HIW "\t看著這壯麗的"HIC"瀑流"HIW"，你不禁感嘆，正所謂「飛流直下三千尺，疑是銀河落九天」啊。\n" NOR; 
                        break;
                case 1:
                        msg += HIW "\t只見"HIC"瀑流"HIW"就像一席倒掛的白簾，氣勢如虹，天地都不禁為之失色。\n" NOR; 
                        break;
                default:
                        msg += HIW "\t只見"HIC"瀑流"HIW"直如水銀洩地一般，水花四濺。\n" NOR; 
                        break;
                }
                msg += HIG "\t你觀賞著飛流直下的水瀑，你不由得感嘆自然造化的奇妙，隱隱對武學也有了一點領會。\n\n" NOR; 
                
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) );
                                        obs[i]->add("popularity", 1 + random(3) );
                                        obs[i]->add("war_art", 1 + random(3) );
                                        obs[i]->add("exp", 25000 + random(25000) );
                                }

                tell_object(room, msg);
               message("world:world1:vision",HIM"【謠言】"+""HIW"天池瀑布"HIM"激流澎湃，奇景非凡，無數遊人嘆羨不已。\n"NOR,users());
        } else {
                switch (random(3))
                {
                case 0:
                        msg = WHT "\n\t瀑流漸漸緩了下來。\n" NOR;
                        break;
                case 1:
                        msg = WHT "\n\t瀑流總是不見有增強的趨勢。\n" NOR;
                        break;
                default:
                        msg = WHT "\n\t瀑流有如小橋流水，叮叮咚咚，離你所期望的相差甚遠。\n" NOR;
                        break;

                }
                msg += HIG "\n\t你心中大感失望。\n\n" NOR;
                tell_object(room, msg);
        }
}

//事件觸發
void trigger_event()
{
        object room;

        if (objectp(room = find_object("/open/world1/acme/area/pool")))
                do_bonus(room);
}

void create() 
{ 
        seteuid(getuid()); 
}

