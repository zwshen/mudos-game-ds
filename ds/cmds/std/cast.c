// cast.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
          string spl, trg, file;
        object target,env;
        
        seteuid(getuid());
        if(me->is_ghost()) return notify_fail(" 你現在還是鬼魂吧\n");
        if( me->is_busy() || me->is_block() )
                return notify_fail("( 你上一個動作還沒有完成﹐不能念咒文。)\n");
        if( sizeof(me->query_temp("is_busy")) ) return notify_fail("你現在正在忙沒空施法。\n");
        if( environment(me)->query("no_magic") || environment(me)->query("no_cast") )
                return notify_fail("這裡不准念咒文。\n");

        if( !arg ) return notify_fail("指令格式﹕cast <法術> [on <目標>]或[at <方向>]\n");
        if( sscanf(arg, "%s on %s", spl, trg)==2 )
        {
                target = present(trg, environment(me));
                if( !target ) target = present(trg, me);

                if( !target ) return notify_fail("這裡沒有 " + trg + "。\n");
                if( !target->is_character() || target->query("damage") )  {
                        if( spl != "life-death-symbol" )
                                return notify_fail("看清楚點，這並不是生物。\n");
                }
        }
        else  if( sscanf(arg, "%s at %s", spl, trg)==2 )
        {
                 env = environment(me);
                 if(stringp(file = env->query("exits/"+trg)))
                 {
                  target = load_object(file);

                  spl = replace_string( spl, " ", "_");
                  if( me->query_spell(spl) > 0 )
                  return (int)SPELL_D(spl)->cast_spell_dir(me, spl, target, trg);
                        else return notify_fail("你還沒學過此咒文。("+spl+")\n");
                 } else return notify_fail("這個方向不能施法。("+spl+")\n");
        }
        else 
        {
                spl = arg;
                target = 0;
        }

        spl = replace_string( spl, " ", "_");
        arg = replace_string( arg, " ", "_");
        if( me->query_spell(spl) > 0 )
                return (int)SPELL_D(spl)->cast_spell(me, spl, target);
        else if( me->query_spell(arg) > 0 )
                return (int)SPELL_D(arg)->cast_spell(me, spl, target);
        
        return notify_fail("你還沒學過此咒文。("+spl+")\n");
}

int help (object me)
{
        write(@HELP
指令格式﹕cast <咒文名稱> [on <施咒對象>]或[at <施法方向>]
 
施法﹐你必需要指定<咒文名稱>﹐<施咒對象>則可有可無。
 
 
HELP
        );
        return 1;
}

