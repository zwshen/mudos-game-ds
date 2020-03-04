inherit NPC;

void create()
{
        set_name("礦工的孩子", ({"Worker's child","child"}) );
        set("long", "這名孩子正在撥弄地上的小土堆，他臉孔漆黑，雙眼黯淡，但是手腳
十分強壯，應該是某名礦工的孩子。\n");
        set("race", "人類");
        set("age", 5);
        set("level", 15);
        set("chat_chance", 10);
        set("chat_msg", ({
"小孩子用手舀水，把水倒在地上的小土堆上...。\n",
(: command("say 應該拿棍子來把這些濕濕的泥土攪一攪...^^。") :),
        }));

        setup();

}
int do_no_ask()
{
  write("請用 say <交談的方式> 來取得所需情報。\n");
  return 1;
}
