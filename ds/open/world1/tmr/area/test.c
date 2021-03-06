// This is a room made by roommaker.

#include <ansi.h> 
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "牌室");
        set("long", "一個相當整齊乾淨的牌室，樸素幽雅、一點也嗅不出緊張的氣氛。\n");
        set("exits", ([
            "west" : __DIR__"inn_2f",
            "east" : __DIR__"big2room2",
        ]));
        set("objects", ([
            "/obj/big2.c" : 1,
         ]));
        set("light",1);
        setup();
        replace_program(ROOM);
} 
void init()
{
        add_action("do_transfer", "transfer");
}

int do_transfer(string arg)

{
        string from, usr;
        int amount;
        object from_ob, me, usr_ob;

        me = this_player();
        if( !arg || sscanf(arg, "%d %s to %s", amount, from, usr)!=3 )
                return notify_fail("指令格式﹕transfer <數量> coin to <玩家>\n");
        usr_ob = LOGIN_D->find_body(usr);
        if( !usr_ob ) return notify_fail("沒有這個使用者\n");                
        from_ob = new("obj/money/"+from);
        if( !from_ob ) return notify_fail("沒有這種錢\n");
        if( amount < 1 ) return notify_fail("一次最少匯一個貨幣。\n");
        if( me->query("bank/past"+from) < amount) return notify_fail("你銀行裡沒有這麼多錢\n");
        tell_object(me, "你將 "+HIY+amount+NOR+" "+from_ob->query("base_unit")+from_ob->query("name")+"匯給"+usr_ob->query("name")+"\n");
        tell_object(usr_ob,HIW"【"HIG"銀"NOR+GRN"行"HIG"通"NOR+GRN"知"HIW"】"NOR+me->query("name")+"匯給你 "+HIY+amount+NOR+" "+from_ob->query("base_unit")+from_ob->query("name")+"\n");
        if( me->query("bank/past"+from) == amount ) me->delete("bank/"+from); 
        else me->add("bank/past"+from, -amount);
        usr_ob->add("bank/past"+from, amount);
        return 1;

}

