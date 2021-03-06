// ball.c, celebrate NBA bull's victory, clone only, temporary obj by grain

#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
        set_name(HIM+"籃球"+NOR, ({ "basket ball", "ball" }));
        if( !clonep() ) {
                set("unit", "顆");
                set("base_unit", "粒");
                set("base_value", 1);
                set("base_weight", 1);
                set("long", "
一顆看起來挺新穎的籃球, 上面刻劃著

 #####   #    #  #       #               #####   #    #  #    #   ####
  #    #  #    #  #       #               #    #  #    #  ##   #  #
   #####   #    #  #       #               #    #  #    #  # #  #   ####
    #    #  #    #  #       #               #####   #    #  #  # #       #
     #    #  #    #  #       #               #   #   #    #  #   ##  #    #
      #####    ####   ######  ######          #    #   ####   #    #   ####

                不知是甚麼意思, 最後還有幾行糢糊字跡, 似乎寫的是
                play [<在場的人>]       :運球 [對誰]
                pass <任何線上的人>     :傳球 <給誰>
                shake                   :搖球
                ");
        }
        setup();
}

void init()
{
        add_action("do_play", "play");
        add_action("do_pass", "pass");
        add_action("do_shake", "shake");
}

int do_play(string arg)
{
        object me, target;
        me=this_player();
        if( me->is_busy() )
                return notify_fail("你正在忙.\n");
        if( arg )
                target=present(arg, environment(me));
        me->start_busy(10);
        if( !target ){
                call_out((:message_vision("\n碰∼　碰碰∼　碰∼  碰碰∼\n", $1):), 1,me);
                call_out((:message_vision("\t$N開始運起球來\n", $1):), 3, me);
                call_out((:message_vision("\t\t$N左轉右切, 跨下運球\n", $1):), 5, me);
                call_out((:message_vision("\t\t\t$N張開大嘴, 晃動著舌頭, 不知道在學誰\n", $1):), 7, me);
                call_out((:message_vision("\n\t碰∼　碰碰∼　碰∼  碰碰∼\n", $1):), 9, me);
        } else {
                call_out((:message_vision("\n碰∼　碰碰∼　碰∼  碰碰∼\n", $1):), 1,me);
                call_out((:message_vision("\t$N開始在$n身旁運起球來\n", $1, $2):), 3, me, target);
                call_out((:message_vision("\t\t$N向著$n左轉右切, 跨下運球, 眼角正瞄著$n\n", $1, $2):), 5, me, target);
                call_out((:message_vision("\t\t\t$N張開大嘴, 晃動著舌頭, 一付要跟$n鬥牛的樣子\n", $1, $2):), 7, me, target);
                call_out((:message_vision("\n碰∼　碰碰∼　碰∼  碰碰∼\n", $1, $2):), 9, me, target);
        }
        return 1;
}

int do_pass(string arg)
{
        object me, target;
        string msg;

        if(!arg) return notify_fail("SYNTAX: pass <ID>\n");
        me=this_player();
        if( me->is_busy() )
                return notify_fail("你正在忙.\n");
        target=find_player(arg);
        if(!target || !interactive(target))
                return notify_fail(arg+"不在線上, 或者已經斷線了.\n");
        if( me==target )
                return notify_fail("傳給別人吧, 由天而降的球你可沒把握能接到.\n");
        if( !this_object()->move(target) )
                return notify_fail(arg+"接不住球, 你還是傳給別人吧.\n");
        msg="你朝天大喊: 萬能的太陽神, 請將此顆籃球砸向 "+target->name()+" , 讓"+gender_pronoun(target)+"下地獄去吧!\n";
        write(HIM+ msg+ NOR);
        msg="\n\t你聽到 "+capitalize(me->query("id"))+" 的嘶喊: \n\t    萬能的太陽神, 請將此顆籃球砸向 "+target->name()+" , 讓"+gender_pronoun(target)+"下地獄去吧!\n";
        message("shout", MAG+ msg+ NOR, users(), me);
        msg="\n碰∼　碰碰∼　碰∼  碰碰∼\n";
        call_out((:message("tell", $1, $2):), 1, msg, environment(target));
        msg="\n\t一顆火紅的球, 由天而降,  咻∼∼磅∼  直接打在你頭上, 你獲得了一顆球\n";
        call_out((:message("tell", HIR+ $1+ NOR, $2):), 2, msg, target);
        target->start_busy(6);
        msg="\n   一顆火紅的球, 由天而降,  咻∼∼磅∼  直接打在 "+target->name()+" 頭上\n    "+target->name()+"兩眼微吊嘴角吐沫, 倒在地上抽慉.\n";
        call_out((:message("tell", $1, $2, $3):), 3, msg, environment(target), target);
        return 1;
}

int do_shake()
{
        string msg;
        if( this_player()->is_busy() )
                return notify_fail("你正在忙.\n");
        this_player()->start_busy(2);
        msg="\t你聽到附近傳來  ∼公∼牛∼加∼油∼ 的聲音\n";
        call_out((:message("tell_r", HIM+ $1 +NOR, $2):), random(4), msg, environment(this_player()));
        call_out((:message("tell_r", HIM+ $1 +NOR, $2):), random(4), msg, environment(this_player()));
        return 1;
}

