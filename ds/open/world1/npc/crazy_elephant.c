inherit NPC;

void create()
{
        set_name("狂象", ({ "crazy elephant", "elephant" }) );
        set("race", "beast");
        set("level",28);
        set("age", 30);
        set("evil",5);
        set("unit","隻");
        set("long", @LONG
發狂中的大象，橫衝直撞，擋者無不受傷掛彩，想馴服牠
可能得費一番工夫。
LONG
);
        set("limbs", ({ "頭部", "身體", "後腳","前腳"}));
        set("verbs", ({ "crash","hoof" }));
        set("attitude", "aggressive");
        setup();
}
