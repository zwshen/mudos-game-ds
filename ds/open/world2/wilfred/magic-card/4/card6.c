inherit __DIR__"std_card.c";
void create()
{
  set("short","精靈族人");
  set("pow", ({1,1,3,1}) );
  set("lv",1);
  set("ver",4);
  set("ver_n","龍槍系列");
  set("num",6);
  set("long",@LONG
精靈族的族人, 都受過基本的戰鬥訓練, 他們的言行舉止中都淡淡的
透出精靈族那種驕傲, 令人難以忍受的氣息, 但是他們在夜間清晰的
夜視力和準確的射箭技巧讓所有意圖與他們為敵的人都為之膽戰心驚
。
LONG
);
  setup();
}