// "undead_item" 此name請勿亂用.
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( HIY "鍾馗娃娃" NOR,({"zhong-kui doll","doll","undead_item"}));
        set_weight(100);
                set("value",0);
                set("no_drop",1);
                set("can_give",1);
                set("unit","隻");
                set("long",@LONG
中元是相當重要的民俗節日，不少人會在舊曆的七月初一到七月卅日之間，
擇日舉辦祭祀活動，以慰在人世間遊玩的眾家鬼魂，並祈求全年的平安順利
。較為隆重者，甚至請來僧、道誦經作法。也有人會在這段時間，請出地藏
菩薩佛像放置高台、或請藝師扮演驅魔大神鍾馗（有的是請藝師操控鍾馗之
傀儡），以消弭死者亡魂的戾氣。
這是一尊鍾馗的小神像，可以替人抵擋閻王的勾魂令。
LONG
                );
                set("undead_msg",HIY"\n\t就在千鈞一髮之際，$N身上的$n化作鍾馗現身，抵消住閻王的這道勾魂令！！\n\n"NOR);

setup();
}

int query_autoload() { return 1; }



