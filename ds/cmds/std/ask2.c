#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object npc;

    if( !arg )
        return notify_fail("你要問誰什麼事﹖\n");

    if( !objectp(npc = present(arg, environment(me))) )
        return notify_fail("這裡沒有這個人。\n");

    if( !npc->is_character() ) {
        message_vision("$N對著$n自言自語....\n", me, npc);
        return 1;
    }

    if( NEWQUEST_D->doReward(npc, me) ) return 1;
    NEWQUEST_D->doAssign(npc, me);
    
    return 1;
}

int help(object me)
{
   write( @HELP
指令格式: ask <某人>

這個指令在解謎時很重要, 通常必須藉由此一指令才能獲得進一步的資訊。
HELP
   );
   return 1;
}
