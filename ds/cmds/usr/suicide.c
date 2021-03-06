// suicide.c
// 不讓巫師可以自殺了, wade 3/17/1996

#include <ansi.h>

inherit F_CLEAN_UP;
void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        if( !arg )
                return notify_fail("自殺會清除你的所有紀錄, 真的要自殺請輸入 suicide -f .\n");

        if( (string)SECURITY_D->get_status(me) != "(player)" )
        {
                write("巫師請先降至玩家(player)才能自殺...\n");
                return 1;
        }

        if( arg!="-f" ) 
                return notify_fail("自殺有兩種﹐您是要永遠死掉還是重新投胎﹖\n");
        if(me->query_temp("suicide_countdown")) return notify_fail("你已經在等死神了...\n");
        write(
                "如果您選擇永遠死掉的自殺方式﹐這個人物的資料就永遠刪除了﹐請務必\n"
                "考慮清楚﹐確定的話請輸入您的密碼﹕");
        input_to("check_password", 1, me, 1);
        return 1;
}

void check_password(string passwd, object me, int forever)
{
        object link_ob;
        string old_pass;

        link_ob = me->query_temp("link_ob");
        old_pass = link_ob->query("password");
        if( crypt(passwd, old_pass)!=old_pass ) {
                write("密碼錯誤﹗\n");
                return;
        }

        if (forever) {
                tell_object( me,
                        HIR "\n\n你決定要自殺了﹐如果十五秒內不QUIT﹐就真的永別了。\n\n\n" NOR);
                me->set_temp("suicide_countdown", 15);
                call_out("slow_suicide",0,me);
        }
}

int slow_suicide(object me)
{
        string  id;
        object link_ob;
        int stage;
        if(!me) return 1;
        stage = me->query_temp("suicide_countdown");
        me->add_temp("suicide_countdown", -1);
        if( stage > 0 ) {
                tell_object(me, HIR "你還有 " + (stage-1) + " 秒的時間可以後悔。\n" NOR);
                call_out("slow_suicide", 2,me);
                return 1;
        }
        if(me->query_temp("map_record")) ROOM_D->moveout(environment(),me);
        link_ob = me->query_temp("link_ob");
        if( !link_ob ) return 0;

        seteuid(getuid());
        rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
        rm( me->query_save_file() + __SAVE_EXTENSION__ );

        log_file("static/SUICIDE",
                sprintf("%s commits a suicide on %s\n", geteuid(me), ctime(time())) );
        // 處理信件等紀錄檔
        if(id =  me->query("id"))
        {
                rm( DATA_DIR + "mail/" + id[0..0] + "/" + id+__SAVE_EXTENSION__);
                rm( DATA_DIR + "signature/" + id[0..0] + "/" + id+".sig");
                rm( DATA_DIR + "note/" + id[0..0] + "/" + id+__SAVE_EXTENSION__);
        }
        write("好吧，回到現實世界之後可要好好加油喔。\n");
        shout( HIW+"\n\n\t天空中那顆代表" + me->name() + "的宿命星殞落了，你似乎可以聽見死神傲慢的輕笑聲。\n\n"+NOR,({me}));
        RECORD_D->remove_record(id);
        CLUB_D->clean_player(id);
        destruct(me);
        return 0;
}

int help (object me)
{
        write(@HELP
指令格式 : suicide [-f || -n]
指令說明 :
             如果因為某種原因你不想活了, 你可以選擇自殺.
             自殺分兩種:

suicide -n : 重新投胎 (清除一切資料，重新設定屬性。)
suicide -f : 永遠的除去玩家資料, 系統會要求你
             輸入密碼以確認身份.

請慎重選擇 :)
HELP
);
        return 1;
}

