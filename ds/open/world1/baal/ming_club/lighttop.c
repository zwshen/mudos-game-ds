#include <ansi.h>
#include <path.h>
inherit ROOM;

int dragon(object me);
int ming(object me);

void create()
{
        set("short", HIR"光明頂"NOR);
        set("long",@LONG
這裡是光明頂，環顧四周，原來這裡就是揚名江湖已久的明教，
身旁豎立一塊碩大的石碑，上面刻道：【當今武林誰人能比，唯我明
教獨步江湖。】前方有一座富麗堂皇的宮殿，上面寫著【聖明宮】三
個大字，明教創立至今已有二十多年，手下十幾萬教徒遍布各地，是
武林中數一數二的大幫，想必明教定是臥虎藏龍，高手雲集之地。
LONG
        );
        set("outdoors","land");
        set("light",1);
 set("exits",([ "east": __DIR__"saintming",
"down": __DIR__"cablecar",
    ]));
        set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
        setup();
}

void init()
{
        ::init();
        ming(this_player());
}

int ming(object me)
{
   object ob;
   if(!userp(me)) // for mob. 避免別幫的招喚生物進入.
   {
        if(ob=me->query("creater"))
        {
                if( !objectp(present("ming plate",ob)) )
                {
                        message_vision("明教教徒大喝: 想混水摸魚? 做你的春秋大頭夢吧你, $N，給老子滾你媽的蛋去！！。\n"NOR,ob);
                me->move(TMR_PAST+"bagi/rift.c");
                        tell_room(environment(me),me->name()+"被明教教徒趕了出來。\n",({ me }));
                        return 1;
                }
        }
   }
    else
   {
if( CLUB_D->check_member("ming",getuid(me))<1 && wiz_level(me)<1)
        {
        message_vision(HIW"明教教徒見$N不是明教的教眾，立即將$N送至街上。\n"NOR,me);
                me->move(TMR_PAST+"bagi/rift.c");
                tell_room(environment(me),me->name()+"被明教教徒給攆了出來。\n",({ me }));
                return 1;
        }
        
        if( me->query_temp("killer") )
        {
                message_vision("天上傳來一個幽幽的聲音: $N, 因為你剛剛殺了人所以暫時不能進入教內。\n"NOR,me);
                me->move(TMR_PAST+"bagi/rift.c");
                tell_room(environment(me),me->name()+"想逃入教內可是被趕了出來。\n",({ me }));
                return 1;
        }
        
        if( me->query_temp("invader") )
        {
                message_vision("天上傳來一個幽幽的聲音: $N, 因為你剛剛攻擊無辜玩家, 所以暫時不能進入教內。\n"NOR,me);
                me->move(TMR_PAST+"bagi/rift.c");
                tell_room(environment(me),me->name()+"想逃入教內可是被趕了出來。\n",({ me }));
                return 1;
        }
        call_out("meeting",2,me);
        return 1;
   }   
}

void meeting(object me)
{
if(!me) return;
        switch( me->query("club/level") )
        {
                case 0:
                case 1:
                        message_vision(HIY"明教教徒對$N說﹕"+"教徒請進！請進！\n"NOR,me);
                break;

                case 2:
                        message_vision(HIY"明教教徒對$N說﹕"+"這位堂員兄弟請進！請進！\n"NOR,me);
                break;

                case 3:
                        message_vision(HIY"明教教徒對$N說﹕"+"護法大人請進！請進！\n"NOR,me);
                break;

                case 4:
                        message_vision(HIY"明教教徒很有禮貌的對$N說﹕"+"堂主大人請進！請進！\n"NOR,me);
                break;

                case 5:
                        message_vision(HIY"明教教徒對$N鞠躬敬禮說﹕"+"光明聖使大人您好呀！\n"NOR,me);
                break;

                case 6:
                        message_vision(HIY"明教教徒看到了$N，趕緊大喊﹕"+"恭迎教主大人駕到！！\n"NOR,me);
                break;
        }
        return;
}
