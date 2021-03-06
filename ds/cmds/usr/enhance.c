// enhance.c 使用加強捲軸
// -Tmr 2007/04/26

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string arg1, arg2;
        string id;
        string s1,s2;
        object scroll, obj, ppl;
        int idx;

        if(!arg || arg == "-query") {
                // 列表
                me->start_more( ENHANCE_D->listScroll(me) );
                return 1;
        }

        if( sscanf(arg, "-put %s", arg1) == 1) {
                // 儲存
                if(!objectp(scroll = present(arg1, me)) )
                        return notify_fail("你身上沒有這種強化卷軸。\n");
                ENHANCE_D->depositScroll(me, scroll);
                return 1;
        }


        
        if( sscanf(arg, "-get %d", idx) == 1 && ( arg == "-get " + idx) ) {
                // 領取
                ENHANCE_D->withdrawScroll(me, idx);
                return 1;
        }

        if( sscanf(arg, "-get %s", id) == 1  ) {
                // 領取
                ENHANCE_D->withdrawScroll_ID(me, id);
                return 1;
        }

        if( sscanf(arg, "%s on %s", arg1, arg2) != 2 ) {
                if( sscanf(arg, "%s", id) == 1 && wizardp(me) ) {
                    ppl = find_player(id);
                    if( !objectp(ppl) )
                        return notify_fail("沒有這個玩家。\n");
                             // 列表
                             me->start_more( ENHANCE_D->listScroll(ppl) );
                        return 1;
                }
                return notify_fail("請 help enhance，獲得詳細的指令格式說明。\n");
        }


        if(!objectp(scroll = present(arg1, me)) )
                return notify_fail("你身上沒有這種強化卷軸。\n");
        if(!objectp(obj = present(arg2, me)) )
                return notify_fail("你身上沒有這種東西。\n");
        
        s1 = obj->query("name");
        s2 = scroll->query("name");
        if( ENHANCE_D->enhance(scroll, obj) == -1 ) {
                        // 衝壞掉，記錄在 news paper 上 tmr 2007/05/03
                RECORD_D->add_scroll_record(
                sprintf( "[%s] %s(%s)" + NOR "對 %s " + NOR "使用一張 %s" + NOR"，但發生恐怖的事了。\n" NOR,
                        ctime(time()), me->query("name"), me->query("id"), s1, s2 )
                );
                }
        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : 

1. enhance
   查詢個人卷軸倉庫的內容。
2. enhance -put [強化卷軸]
   儲存一張強化卷軸至你的個人卷軸倉庫中
   每次儲存需花費 100 coin 手續費。
3. enhance -get [index]
   取出 第index張 強化卷軸。
4. enhance -get [id]
   取出第一張卷軸英文字中有出現 id 的強化卷軸。
5. enhance [強化卷軸] on [武器或防具]
   對一件武器或防具使用加強卷軸。

倉庫可存卷軸張數基本為200張，角色51級之後，
每一級可多存16張，至100級時，共可以儲存1000張。

相關設定，請參考 help scroll。
HELP
);

    return 1;
}

