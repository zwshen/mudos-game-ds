inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("苦蒜", ({ "smell bad garlic", "garlic" }));
        set("long",@LONG
這是一種特別的蒜頭, 味道比一般料理用到的蒜頭要來得苦,
它是一種藥材, 以製作治皮外傷的藥為主, 它可以生吃, 不過嘗
起來的味道有多爛就不得而知囉。
LONG
);
// 現在 obj long 要用和 room 的 long 一樣寫法, faceoff
// 你要注意這點.
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("material","plant");
// 苦蒜的材質當然是 plant 植物囉...其他藥材有需要不同材質的,
// 再看看 mt all 
                set("value", 20);
// 非特殊藥材, 價格不要過高, 幾十塊錢就算不錯了.
                set("heal_hp",5);
//              set("heal_mp",-35); <---- 這行我註解掉了, 因為 heal 值
//                                        不能是負的.
// 因為是可生吃的藥材, 若該藥材非特效藥材,
// 請記得至少有一項是扣的. 要不然吃藥材就好了,
// 製藥幹什麼:p 
                set("heal_ap",30);
                set("attr/wound",4);  
// attr/wound 是此藥材對回復 wound(外傷)的量, 
// 此外還有 attr/hp  attr/mp  attr/ap.
                set("attr_one","plant"); 
// attr_one 是指此物為植物性 or 動物性, 動物性就把 plant 改成 animal.
                set("attr_two","yin");  
// attr_two 是指此物為陰屬或陽屬, 屬陰者為 yin, 陽者為 yang.
// 以上 attr_one  attr_two 與 attr/ 三個藥材屬性請照我 post 
// 的表來改.
                set("food_remaining", 1);   //表示該藥材可以生吃, 所以加這項
                set("eat_msg","$N吃下一顆正在散發惡臭的苦蒜..!\n");
                set("eff_msg","你覺得頭有點暈, 不過體力好像回復了一點..\n");
// eat_msg 是吃物品時大家看得到的 msg, eff_msg 是吃完的 msg, 只有自己看得到
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

//這個部份是對應吃了此藥材有扣東西才寫的,
//要不然沒限制的話, ppl 就算吃到 mp -1
//也可以一直吃..反正 mp 底限是 -1.
//記得有扣東西的飲食服用之物千萬要加 do_eat or do_drink ...
//並要這樣寫..

int do_eat(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        me=this_player();
        if(me->query("mp")<34)
        {
                return notify_fail("你的精神力(MP)已經不夠了, 再吃就破表囉。\n");
        }
        else
        {
                set("heal_ap",30);
                me->receive_damage("mp",35);
      
          set("heal_hp",5);
                return ::do_eat(arg);
        }
}
