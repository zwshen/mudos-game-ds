// 古墓-仙人劍舞
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
                message("world:world1:vision",HIM"【謠言】"+"聽說活死人墓懸崖出現"HIW"仙人劍舞"HIM"，仙影玄奇，令人匪夷所思。\n"NOR,users());
                return;
        }

          r = random(300);
        chance = sizeof(obs);
        if(chance > 20 ) chance = 20;
          
          if (r < chance )
        {
                msg = HIW "\n\t只見皎潔的月光下，兩個飄逸絕倫的身影倒映在對面山壁之上，持劍翩翩起\n"
                           "\t舞，劍光頓挫，仙影迴翔。你不由驚嘆：寰宇之中，竟有如此絕奧之技，今\n"
                           "\t日有緣得見仙人之姿，實在是福分非淺。\n" NOR;
                msg += HIG "\t你對仙人的劍舞頗有所感，武學上頓時有了新的領悟。\n\n" NOR;

                // 增加聲望跟戰鬥藝術
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 10 + random(5) );
                                        obs[i]->add("war_art", 10 + random(5) );
                                        obs[i]->add("exp", 50000 + random(50000) );
                    }
                    
                tell_object(room, msg);
                message("world:world1:vision",HIM"【謠言】"+"聽說活死人墓懸崖出現"HIW"仙人劍舞"HIM"，仙影玄奇，令人匪夷所思。\n"NOR,users());
         } else  if (r < 200)   {
                        msg = HIW "\n\t皎潔的月光下，壁上能隱隱約約倒影出仙人之姿。實乃世間僅有。\n"NOR;
                
                switch (random(3))
                {
                case 0:
                        msg += HIC "\t只見對面山壁上仙影一閃即過，身形之敏捷，令你根本無法捕捉。\n" NOR;
                        break;
                case 1:
                        msg += HIC "\t只見山壁上閃過幾道仙影，似乎是施展一種奇妙無比的武功\絕學。\n" NOR;
                        break;
                default:
                        msg += HIC "\t忽然間兩個飄逸絕倫的身影顯映在對面山上，但仙影轉瞬即逝，你根本無法看清。\n" NOR;
                        break;
                }
                msg += HIG "\t你受到了仙影的感悟，武學方面又有了一些體會。\n\n" NOR;
                
                for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;

                                        obs[i]->add("popularity", 1 + random(2) );
                                        obs[i]->add("war_art", 1 + random(2) );
                                        obs[i]->add("exp", 10000 + random(10000) );
                                }

                tell_object(room, msg);
                message("world:world1:vision",HIM"【謠言】"+"聽說活死人墓懸崖出現"HIW"仙人劍舞"HIM"，仙影玄奇，令人匪夷所思。\n"NOR,users());
        } else {
                switch (random(3))
                {
                case 0:
                        msg = WHT "\n\t眼見皎潔的月光升起，可是一團雲飄過，遮蓋\了月光，你眼前頓時一片漆黑。\n" NOR;
                        break;
                case 1:
                        msg = WHT "\n\t你目不轉睛的注視著對面的玉壁，可剎那間雷聲轟鳴，山風捲雲，將月光遮了個嚴實。\n" NOR;
                        break;
                default:
                        msg = WHT "\n\t夜晚已至，可一團團濃厚的雲層卻籠罩著天空，你連對面的山頭都無法看清。\n" NOR;
                        break;
                }
                msg += HIG "\t你不禁嘆息道：「怎奈緣分未至，無緣窺視仙影！」\n" NOR;
                tell_object(room, msg);
        }
}

//事件觸發
void trigger_event()
{
        object room;

        if (objectp(room = find_object("/open/world1/tmr/gumu/xuanya")))
                do_bonus(room);
}

void create() 
{ 
        seteuid(getuid()); 
}


