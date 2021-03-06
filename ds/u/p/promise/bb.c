#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob;

        seteuid(getuid(me));
        if(!str) return notify_fail("指令格式: shutup <使用者>\n");
        ob = LOGIN_D->find_body(str);
        if(!ob) return notify_fail("線上的使用者中沒有這個人。\n");
        if(wiz_level(me) <= wiz_level(ob))
        return notify_fail("以下犯上，想死也不是這樣。\n");

        seteuid(geteuid(ob));
        if (ob->query("shutup") == "on")
        {
                ob->delete("shutup") ; 
                tell_object(ob, "巫師("+me->query("id")+")取消你的禁言\n");
                tell_object(me,"你取消了玩家("+ob->query("id")+")的禁言\n");
                tell_object(users(),HIW"\n　　　((((("HIR"天神"HIY"呼嘯"HIW")))))　　　"NOR""HIM+ob->name()+NOR"以後願遵守"HIC"ｒｕｌｅｓ"NOR"，巫師"HIW+me->name()+NOR"特網開一面，恢復權力！\n\n"+NOR);
        }
        else
        {
                ob->set("shutup", "on") ;
                tell_object(ob, "巫師("+me->query("id")+")禁止你使用公共頻道\n");
                tell_object(me,"你啟動玩家("+ob->query("id")+")的禁言\n");
                tell_object(users(),HIW"\n　　　((((("HIR"天神"HIY"呼嘯"HIW")))))　　　"NOR""HIM+ob->name()+NOR"因違反"HIC"ｒｕｌｅｓ"NOR"，所以被巫師"HIW+me->name()+NOR"禁言！\n\n"+NOR);
        }
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : quiet <某人>

對被禁言者再次使用quiet 就能夠取消禁言
此指令可讓你(妳)將某人禁止使用公用頻道。
HELP
    );
    return 1;
}

