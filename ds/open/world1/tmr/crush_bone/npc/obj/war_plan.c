inherit ITEM;

void create()
{
    set_name("碎骨寨作戰計劃", ({"crush bone war plan", "plan", "_CRUSH_BONE_WAR_PLAN_"}));
    if( !clonep() ) {
        set("long", "一張破牛皮紙，畫了不知什麼地方的地圖，上頭還有一些紅色箭頭指標。");
        set("unit", "張");
        set("value", 10);
        set("weight", 50);
    }
    setup();
}

