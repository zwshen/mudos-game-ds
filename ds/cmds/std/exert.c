// cast.c
// 把所有query_skill()-> query_learn(),為免player死到變0 後不能使用技能.
// by alickyuen on 24-08-2002

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string spl, trg;
        string sk_arg;
        object target;

        
        seteuid(getuid());
    if(me->is_ghost()) return notify_fail("     你現在還是鬼魂吧。\n");
        if( me->is_busy() || me->is_block() )
                return notify_fail("( 你上一個動作還沒有完成﹐不能施展技能或武功\。)\n");

        if( environment(me)->query("no_exert") )
                return notify_fail("這裡不准使用特殊技能。\n");

        if( !arg ) return notify_fail("指令格式﹕exert <技能或武學> [on <目標>]或[at <方向>]\n");

        if( sscanf(arg, "%s on %s", spl, trg) == 2 )
        {
                target = present(trg, environment(me));
                if( !target ) target = present(trg, me);
                if( !target ) return notify_fail("這裡沒有 " + trg + "。\n");
                sk_arg = trg;
        } else if( sscanf(arg, "%s %s", spl, sk_arg) == 2 ) {
                 target = 0;
        } else {
                spl = arg;
                sk_arg = 0;
        }

        sscanf(spl, "%s %s", spl, sk_arg);


    if( me->query_learn(spl) > 0 || me->query_skill(spl) )
                        return (int)SKILL_D(spl)->cast_skill(me, spl, target, sk_arg);

        return notify_fail("你還沒學過此技能或武功\。(" + spl + ")\n");
}

int help (object me)
{
        write(@HELP
指令格式﹕exert <技能或武學> [on <施展對象>]或[at <施展方向>]
 
使用技能﹐你必需要指定<武學或技能名稱>﹐<對象>及<方向>的需要與否
則視技能之功能而定。

在你施展某一個武功或技能之前﹐你必須學過此武學或是技能。
 
HELP
        );
        return 1;
}

