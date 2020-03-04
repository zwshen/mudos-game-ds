#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("戰斧", ({ "battle axe","axe","_OBJ_ID_BATTLE_AXE_"}) );
        set_weight(8000);
        setup_axe(4, 6,100, 0);
        if( !clonep() ) {
                set("wield_as", ({"twohanded axe"}));
                set("unit", "把");
                set("value", 4500);
                set("rigidity", 60);
                set("long",@long
這是一把非常沉重的大斧頭，斧柄上刻畫著一個赤裸著上身的壯悍男
子，正雙握著斧頭對抗一隻野獸的圖案，雖然只寥寥數筆，但畫面生動而
寫實，似乎真發生過這種事的樣子。
long
                );
        }
        setup();
}



