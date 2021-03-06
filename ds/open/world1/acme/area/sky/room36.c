// Room36.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;
string look_book(object me);

void create()
{
        set("short","【地剎堂】");
        set("long", @LONG
你一眼看去，舉目都是琳瑯滿目的武功密笈，原來這裡是天地會
存放經籍的所在，在中央的桌上放著一本書籍(book)，上面寫著：「
天地正法」你不禁想翻閱(read)它。

LONG
        );
        set("exits", ([
                "west": __DIR__"room35",
        ]));
        set("item_desc",([
        "book":(: look_book :),
        "table": "這張桌子(table)似乎可以推動(push)。\n",
        ]));


        set("objects" , ([
//            __DIR__"item/equip_shelf" : 1,
            __DIR__"item/item_box" : 1, // 2005.5.30 add by whoami
//            __DIR__"item/weapon_shelf" : 1,
        ]));
        set("light",1);
        set("no_kill",1);
set("no_goto",1);
        setup();
        set("stroom",1);
}
void init()
{
 add_action("do_push","push");
 add_action("do_read","read");
}

int do_read(string arg)
{
        if(arg=="book")
        {
                this_player()->start_more(@SKY_RULES
        
                           【天地會幫規】
一、  嚴格禁止跨幫

      本幫幫員所擁有之所有角色(就是分身囉)，不可以加入其他幫派
      這樣是避免各幫派之間的無謂鬥爭。
      同時也各位不要將自己的角色借給他人使用。而要把角色送給他
      人時，必須POST在幫會的 Terra Board公佈，由長老以上同意並
      將之Kickout後才可送給他人。
      如送給同幫幫員,可以POST在Terra Board，由長老同意。
      另外禁止任意脫離本會，如自己脫離幫會，不要希望本會重新收
      你，而有必要脫離時，必須POST在 Terra Board經長老會議通過
      准許，始可離開幫會。
      違反上述規定者，將逐出族，並會由幫主決定是否加以通緝之。

二、  嚴禁主動PK其他玩家

      本幫幫員禁止PK其他玩家，但由本幫發出格殺令的例外。
      而所有PK我幫幫員之玩家，應立即通知在線之長老人員，並將情
      況POST在Terra Board，內容必須必須包括PKER ID和被PK者ID，
      而在線的幫員,應給与最大協助。
      而本幫將列出通緝黑名單，我幫幫眾皆可除之。若被PK時，線上
      無長老以上可為之作證，則請被PK之幫眾自行POST過程，事後經
      長老或以上人員查證，亦將之列入通緝黑名單。

      除遭受PK以外，本幫幫眾與他人的其他糾紛，必須POST在
      Terra Board由長老以上決定行動，不可自行PK對方。
      違反上述規定者，將逐出本族，並由幫主視情況決定是否加以通
      緝。

SKY_RULES
);
        return 1;
        }
        notify_fail("你想要閱\讀什麼?\n");
        return 0;
}

string look_book(object me)
{
        return @SKY_BOOK
        
你看到這本書的封面上寫著【天地正法】四個大字，如果你想了解這本
書的內容或許你可以試著閱讀看看(read book)。

SKY_BOOK;
}

int do_push(string arg)
{
        object room;
        if(!arg) return notify_fail("你要推動什麼?\n");
        if(arg!="table" && arg !="桌子") return notify_fail("你不知道要怎麼推那個東西。\n");
        if(this_object()->query("exit/down")) return notify_fail("桌子已經被堆到牆邊卡住了。\n");
        if( !room = load_object(__DIR__"cave") ) return notify_fail("出口並不存在。\n");
        set("exits", ([
                "west": __DIR__"room35",
                "down": __DIR__"cave",
]));
        room->set("exits/up",__FILE__);
        set("item_desc",([
        "book":(: look_book :),
        "table": "這張桌子似乎是不久前才被人堆到牆邊的。\n",
        ]));
        create_door("down","地窖鐵蓋\","up",DOOR_LOCKED,"skykey");
        room->create_door("up","地窖鐵蓋\","down",DOOR_LOCKED,"skykey");
        message_vision("$N用力將桌子移到旁邊, 赫然發現一個鐵蓋\子。\n",this_player());
        return 1;
}

