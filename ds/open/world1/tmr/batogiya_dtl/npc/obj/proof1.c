inherit ITEM;

void create()
{
    set_name("哈哈村選舉不公證據其一", ({ "haha 1 proof", "proof", "_HAHA_PROOF_1_" }));
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 0);
        set("long",@long
一本由「福小姐」花了七天觀看電視新聞畫面所得到的厲害證據，
或許可以讓「哈顫」能平反的證據。
long
);
    }
    setup();
}

