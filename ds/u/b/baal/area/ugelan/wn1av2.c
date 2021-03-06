#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"幽遮蘭城─德愛爾夫大道(The Avenue of Elf)"NOR);
        set("long", @LONG
雖說處在城內的邊緣地帶，德愛爾夫大道的熱鬧程度跟
杜瓦夫、修曼大道等主要幹道相比，可是一點也不遜色，畢
竟幽遮蘭城以德愛爾夫大道和巴巴瑞安大道之間，可是幽遮
蘭城的城東市集所在處呢，這裡人來人往，熱鬧非凡，旁邊
是一家賣蔬果的店舖。
LONG
        );
        set("exits", ([ 
                        "north": __DIR__"wn1av3",
                        "east" : __DIR__"vegetablestore1",
                        "south": __DIR__"wn1av1",
            ]));
           set("item_desc",([
"魔法路燈" : "
一個極為漂亮，由玻璃製成的魔法路燈，裡面有著魔法所召
換出的火燄，所以不需要燃料，但是每過一段時間就得由城
內的魔法師重新招喚才行。\n",
"水溝" : "在人行道兩邊的凹槽，深約一呎，裡面積了些樹葉跟垃圾，
可在下雨時幫忙疏導積水至下水道裡。\n",
                 ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}

