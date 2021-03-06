// 冰湖-流星雨
// tmr 2006/11/14

#include <ansi.h>

// 獎勵
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int r,i;
        int chance;

        obs = all_inventory(room);
        chance = sizeof(obs);
        if(chance > 20 ) chance = 20;
        if (sizeof(obs) < 1) {
                message("world:world1:vision",HIM"【謠言】"+"聽說冰湖夜空竟現"HIW"流星雨"HIM"，五彩繽紛，煞為壯觀。\n"NOR,users());
                return;
        }

          r = random(400);
          if (r < chance )
         {
                msg = HIC "\n\t只聽天空驟然傳來一陣刺耳的摩擦聲，你仰望上蒼，發現穹蒼裡已豁然出現\n"
                           "\t無數顆流星。夜隕如雨飛墜，鋒芒劃空，爾落入天池之中，又再激起萬股七色\n"
                               "\t浪濤，漆黑夜穹竟猶如白晝一般。你不禁感嘆，大自然之威，當真神鬼莫測。\n" NOR;

                msg += HIG "\t你仔細的觀察了流星雨的全過程，發現其中竟有很多奧秘可以融於武學。\n\n" NOR;

                // 增加聲望跟戰鬥藝術
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 10 + random(10) );
                                        obs[i]->add("war_art", 10 + random(10) );
                                        obs[i]->add("exp", 50000 + random(50000) );
                    }
                    
                tell_object(room, msg);
                message("world:world1:vision",HIM"【謠言】"+"聽說冰湖夜空竟現"HIW"流星雨"HIM"，五彩繽紛，煞為壯觀。\n"NOR,users());
        } else  if (r < 200)   {
                msg = HIC "\n\t只聽遠處一陣刺耳的摩擦聲，舉目望去，發現竟有流星從天邊劃過，\n"
                          "\t怎奈距隔委實太遠，根本無法看清。\n" NOR;

                msg += HIG "\t你觀罷流星，隱隱的對武學有了一絲體會。\n\n" NOR;
                
                
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;

                                        obs[i]->add("popularity", 3 + random(3) );
                                        obs[i]->add("war_art", 3 + random(3) );
                                        obs[i]->add("exp", 25000 + random(25000) );
                                }

                tell_object(room, msg);
                message("world:world1:vision",HIM"【謠言】"+"聽說冰湖夜空竟現"HIW"流星雨"HIM"，五彩繽紛，煞為壯觀。\n"NOR,users());
        } else {
                switch (random(3))
                {
                case 0:
                        msg = WHT "\n\t眼見天邊一片明亮，知是流星雨將至，可怎奈間隔遙且雲層厚，卻無緣得見。\n" NOR;
                        break;
                default:
                        msg = WHT "\n\t眼見天邊一片明亮，但是水氣，霧氣和雲層交雜，讓你什麼都看不清楚。\n" NOR;
                        break;
                }
                msg += HIG "\n\t你不禁嘆息道：「太可惜了...」\n" NOR;
                tell_object(room, msg);
        }
}

//事件觸發
void trigger_event()
{
        object room;

        if (objectp(room = find_object("/open/world1/tmr/bagi/ghat6")))
                do_bonus(room);
}

void create() 
{ 
        seteuid(getuid()); 
}

