inherit NPC;

void create()
{
        set_name("聖狼", ({ "saint wolf", "wolf" }) );
        set("race", "beast");
        set("level",35);
        set("age", 19);
        set("evil",-20);
        set("unit","隻");
        set("long", @LONG
黑色毛的豹子，炯炯有神的眼睛，蓄勢待發的姿態，實在
守護神殿遺跡的聖狼，對於入侵者會給於毫不留情的攻擊
，直到趕走入侵者為止。
LONG
);
        set("limbs", ({ "頭部", "身體", "後腳","前腳"}));
        set("verbs", ({ "crash","hoof","bite" }));
        //set("attitude","killer");
        set("attitude","aggressive");
        setup();
}

