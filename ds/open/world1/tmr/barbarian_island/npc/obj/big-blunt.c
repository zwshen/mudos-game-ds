#include <weapon.h>

inherit F_BLUNT;

void create()
{
        set_name("大木棒", ({ "big wood blunt", "blunt" }) );
        set_weight(7000);
        setup_blunt(6, 5, 100, 0);

        if( !clonep() ) {
                set("wield_as", ({"twohanded blunt" }));
                set("unit", "把");
                set("value", 100);
                set("rigidity", 80);
                set("long",@long
這是個用硬質橡木做成的大木棒，力量稍嫌不足的人實在拿不起這麼重的武器。
long
);
        }
        setup();
}


