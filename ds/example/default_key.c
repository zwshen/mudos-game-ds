inherit ITEM;

void create()
{
  set_name("寶箱鑰匙", ({ "default box key", "key" }));
  set("long", @LONG
這是一個普通的鑰匙, 沒什麼特別之處。
LONG
  );
  set_weight(1);
  set("unit", "隻");
  setup();
}
