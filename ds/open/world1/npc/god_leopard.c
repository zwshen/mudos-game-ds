inherit NPC;

void create()
{
        set_name("神豹\", ({ "god leopard", "leopard" }) );
        set("race", "beast");
        set("level",34);
        set("age", 8);
        set("evil",-20);
        set("unit","隻");
        set("long", @LONG
黑色毛的豹子，炯炯有神的眼睛，蓄勢待發的姿態，實在
是美的讓人無法置信。
LONG
);
        set("limbs", ({ "頭部", "身體", "後腳","前腳"}));
        set("verbs", ({ "crash","hoof","bite" }));
        set("attitude","aggressive");
        setup();
}



