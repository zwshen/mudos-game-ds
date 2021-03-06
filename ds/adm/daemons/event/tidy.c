// qiantang.c 事件：錢塘江潮信
// for XKX100 , by Sir 2003.11.3

#include <ansi.h>

// 獎勵
private void do_bonus(object room)
{
        object *obs;
        string msg;
        int r,i;

        obs = all_inventory(room);
        if (sizeof(obs) < 1) {
                message("world:world1:vision",HIM"【謠言】"+"磐龍險灘竟現"HIC"潮信"HIM"，聲如金鼓，奮如雷霆，非常壯觀。\n"NOR,users());
                return;
        }
       
                  if( random(100) < 75) {
                        msg =  "\n\t只見天空萬里無雲，磐龍險灘潮水平靜無波。\n" NOR;
                            msg += HIG "\n\t你不禁嘆息道：「太可惜了...」\n" NOR;
                        tell_object(room, msg);
                            return;
                }
        
                msg = HIC "\n\t每年八月十八磐龍險灘漲潮，非常準時，故稱之為潮信。 \n"
                          "\t每次潮水來臨時波濤洶湧，氣勢逼人，十分壯觀。\n";NOR;
        msg += HIC "\t只聽「隆隆」一陣雷鳴響過，潮水如湧一般的向岸邊捲來。\n"
                  "\t剎那間，漫江沸騰，波濤萬頃，潮高丈餘，萬馬奔騰，真有\n"
                  "\t『濤來勢轉雄，獵獵駕長風。雷震雲霓裡，山飛霜雪中』的\n"
                  "\t壯麗氣勢！正所謂『遠若素練橫江，聲如金鼓；近則亙如山\n"
                  "\t嶽，奮如雷霆』。一時間你不禁沉浸當中，天地萬物都已然\n"
                  "\t忘懷了。\n" NOR;
                                   
         msg += HIG "\n\t你望著洶湧的潮水，若有所悟，對武功\又有了新的體會。\n\n" NOR;
               for ( i = 0 ; i < sizeof(obs); i++)
                {
                        if( !living(obs[i]) || !userp(obs[i]) ) continue;
                                        obs[i]->add("popularity", 10 + random(5) );
                                        obs[i]->add("war_art", 10 + random(5) );
                                        obs[i]->add("exp", 50000 + random(5000) );
                                }

                tell_object(room, msg);
                message("world:world1:vision",HIM"【謠言】"+"磐龍險灘竟現"HIC"潮信"HIM"，聲如金鼓，奮如雷霆，非常壯觀。\n"NOR,users());
}

// 事件觸發
void trigger_event()
{
        object room;
                
        // 錢塘江潮信
        if (objectp(room = find_object("/open/world1/wilfred/sand/room42")))
                do_bonus(room);
                
}

void create() 
{ 
        seteuid(getuid()); 
}

