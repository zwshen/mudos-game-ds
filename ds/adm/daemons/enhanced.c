// enhanced.c 武器/防具強化捲軸
// Tmr 2007/04/26

// Tmr 2007/07/11 加上可存捲軸的上限

#include <ansi.h>

// 強化可允許次數
#define MAX_TIMES 7

int getMaxTimes() { return MAX_TIMES; }

// 捲軸路徑
#define SCROLL_PATH "/open/enhance/"

#define LV5_SET ({ \
        "100_str", "100_dex", "100_int", "100_str", \
        "100_hp", "100_ap", "100_mp", \
        "100_atk", "100_def", "100_shd", \
})

#define LV10_SET ({ \
        "60_hp", "60_ap", "60_mp", \
        "60_atk", "60_def", "60_shd", \
})

#define LV15_SET ({ \
        "70_hp", "70_ap", "70_mp", \
        "70_atk", "70_def", "70_shd", \
})

#define LV20_SET ({ \
        "60_str", "60_int", "60_dex", "60_con", \
        "10_hp", "10_ap", "10_mp", \
        "10_atk", "10_def", "10_shd", \
})

#define LV30_SET ({ \
        "70_str", "70_int", "70_dex", "70_con", \
        "30_hp", "30_ap", "30_mp", \
        "30_atk", "30_def", "30_shd", \
})

#define LV40_SET ({ \
        "10_str", "10_int", "10_dex", "10_con", \
})

#define LV45_SET ({ \
        "30_str", "30_int", "30_dex", "30_con", \
})

#define LV50_SET ({ \
        "10_bar", "10_bio", "10_wit", "10_sou", "10_tec", \
        "10_hit_r", "10_hit_p", "10_hit_d", \
})

#define LV60_SET ({ \
        "30_bar", "30_bio", "30_wit", "30_sou", "30_tec", \
        "30_hit_r", "30_hit_p", "30_hit_d", \
})

// 玩家可以儲存的基本 scroll 張數
#define MAX_DEPOT 200
#define DEPOT_PER_LEVEL 16
#define DEPOSIT_COST 100

int getMaxDepot(object me) {
        if(!me) return MAX_DEPOT;
        if(me->query("level")<=50) return MAX_DEPOT;
        return MAX_DEPOT + (me->query("level")-50) * DEPOT_PER_LEVEL;
}

void depositScroll(object me, object scroll)
{
        if( !scroll->query("is_enhance") ) {
                tell_object(me, "這不是一張強化捲軸。\n");
                return;
        }

        if(me->query("bank/past") < DEPOSIT_COST ) {
                tell_object(me, "你的存款不足，無法儲存卷軸。\n");
                return;
        }

        if( me->getDepotSize() >= getMaxDepot(me) ) {
                tell_object(me, "你個人卷軸倉庫已經滿了，無法再存入更多東西。\n");
                return;
        }

        me->add("bank/past", -DEPOSIT_COST);
        me->depotItem( base_name(scroll) );

        tell_object(me, "你將"+ scroll->query("name") + "存入個人卷軸倉庫。\n" NOR);
        destruct(scroll);
}

void withdrawScroll(object me, int idx)
{
        int size;
        object ob;

    size = me->getDepotSize();
        
        if( idx < 0 || idx >= size) {
                tell_object(me, "你的個人卷軸倉庫中，並沒有這一張卷軸。\n");
                return;
        }

        ob = new(me->getDepotItem(idx));
    if( !objectp(ob) ) {
                tell_object(me, "目前無法領出這張卷軸，請通知巫師處理。\n");
                return;
        }

        if(!ob->move(me) ) {
                tell_object(me, "你身上的東西太多了，無法領出卷軸。\n");
        destruct(ob);
                return;
        }
        
        me->deleteDepotItem(idx);
        tell_object(me, "你從個人卷軸倉庫中領出"+ ob->query("name") + "。\n" NOR);
}


// 利用 id 來找 scroll
void withdrawScroll_ID(object me, string id)
{
        int idx, size;
        object ob;

        size = me->getDepotSize();
        if( size <= 0) {
                tell_object(me, "你的個人卷軸倉庫中，沒有任何卷軸。\n");
                return;
        }

        for(idx = 0;idx < size;idx++) {
            ob = new(me->getDepotItem(idx));
            if( !objectp(ob) ) continue;
                if( strsrch(ob->query("id"), id) != -1 ) {
                        destruct(ob);
                        withdrawScroll(me, idx);
                        return ;
                }
                destruct(ob);
        }
        
    tell_object(me, "你的個人卷軸倉庫中，沒有這種卷軸。\n" NOR);
}

string listScroll(object me)
{
        int i, size, ct;
        string msg;
        string* items;
        object ob;

        items = me->getAllDepotItems();
    size = sizeof(items);

    msg  = HIY"─────────────────────────────────────────\n"NOR;
    msg += sprintf("目前儲存有 %4d/%4d 張卷軸\n", size, getMaxDepot(me) );
    msg  += HIY"─────────────────────────────────────────\n"NOR;
    for(i=0, ct = 1;i<size;i++, ct++) {
        if( !objectp(ob = load_object(items[i])) ) continue;
        msg += sprintf("%4d：%24s" NOR, i, ob->query("name"));
        if(ct==4) {     // 四份就換行
                msg+="\n";
                ct = 0;
        }
        destruct(ob);
    }
    msg  += HIY"\n─────────────────────────────────────────\n"NOR;

//      me->start_more(msg);
        return msg;
}


// 掉捲機率
int isDropScroll() {
        // 1%
        return (random(100) == 1);
}

string* possbileScrollSet(int lv)
{
        string* set = ({});
        if(lv<5) return set;
        if(lv>=5) set += LV5_SET;
        if(lv>=10) set += LV10_SET;
        if(lv>=15) set += LV15_SET;
        if(lv>=20) set += LV20_SET;
        if(lv>=30) set += LV30_SET;
        if(lv>=40) set += LV40_SET;
        if(lv>=45) set += LV45_SET;
        if(lv>=50) set += LV50_SET;
        if(lv>=60) set += LV60_SET;

        return set;
}


int success(int p)
{
        return random(100) < p;
}

int release = 0;

int getTotal() { return release; }

// 產生捲軸，依NPC等級判斷
object createScroll(int lv)
{
        int size;
        string *set = possbileScrollSet(lv);
        size = sizeof(set);
        if( size == 0) 
                return 0;       // 沒有元素可以用
        release++; // 產出數+1
        return new( SCROLL_PATH + set[random(size)] + ".c");
}

int count(string type, int p)
{
        switch(type) {
                case "str": case "dex": case "con": case "int":
                     if( p == 100 ) return 1;
                     if( p == 60 ) return 2;
                     if( p == 70 ) return 2;
                     if( p == 30 ) return 5;
                     return 5;
                case "hp": case "mp": case "ap":
                        if( p == 100 ) return 20;
                        if( p == 60 ) return 40;
                        if( p == 70 ) return 40;
                        if( p == 30 ) return 90;
                        return 90;
               case "damage":
                        if( p == 100 ) return 2;
                        if( p == 60 ) return 5;
                        if( p == 70 ) return 5;
                        if( p == 30 ) return 9;
                        return 9;
                case "shield": case "armor":
                        if( p == 100 ) return 5;
                        if( p == 60 ) return 10;
                        if( p == 70 ) return 10;
                        if( p == 30 ) return 20;
                        return 20;
                case "bar": case "bio": case "wit": case "sou": case "tec":
                      return 1;
                case "hit_r": case "hit_d": // 暴擊率、暴擊抵抗
                        if( p == 100 ) return 1;
                        if( p == 60 ) return 1;
                        if( p == 70 ) return 1;
                        if( p == 30 ) return 4;
                        return 2;
                case "hit_p": // 暴擊傷害
                        if( p == 100 ) return 3;
                        if( p == 60 ) return 6;
                        if( p == 70 ) return 6;
                        if( p == 30 ) return 20;
                        return 10;
        }
        return 0;
}


void enhanceObj(object scroll, object obj, string prop) 
{
        string type;
        int eff;

        type = scroll->query("eff_type");
        eff = count(type, scroll->query("eff_p"));
        
        obj->add( prop + "/" + type, eff);
}

int enhance(object scroll, object obj) 
{
        string prop, eff_type;
        if( !scroll->query("is_enhance") ) {
                write("這不是一張強化捲軸。\n");
                return 1;
        }

         prop = obj->query("armor_prop") ? "armor_prop" : "NULL";
         if( prop == "NULL" && obj->query("skill_type") )
                prop = "weapon_prop";

         if( prop != "armor_prop" && prop != "weapon_prop")  {
                write("強化捲軸只能用在武器及防具上面。\n");
                return 1;
        }


        if( obj->query("equipped") ) {
                write("請先把這件裝備拿下來。\n");
                return 1;
        }


        if( obj->query_autoload() ) {
                write("強化捲軸無法使用在 save item 上。\n");
                return 1;
        }

        if( obj->query("enhance_times") >= MAX_TIMES ) {
                write("這件物品已經超過可允許\的強化次數了。\n");
                return 1;
        }
        
        obj->add("enhance_times",1);    // 次數加1
        eff_type = scroll->query("effect_type");

        if( success(scroll->query("eff_p") ) ) {
       message_vision( HIY "$N"HIY"發出刺眼的光芒，$n"HIY"變的不一樣了。\n" NOR, scroll, obj);
                enhanceObj(scroll, obj, prop);
        obj->add("long",
                     sprintf( HBK "[%s] 使用 %s " HIW "成功\。\n" NOR, ctime(time()), scroll->query("name")  ) );
        } else {
                if( (scroll->query("eff_p") == 30 || scroll->query("eff_p") == 70) 
                        && random(100) > 50 ) {
                        // 邪惡性質，有50%機率會毀壞物件
                                message_vision( HBK "$N"HBK"與$n"HBK"一起化作恐怖的黑煙，馬上就被風吹散，消失不見了！！\n" NOR, scroll, obj);
                            destruct(obj);
                                        destruct(scroll);
                                                return -1;       // 表示衝壞掉
                } else {
                        message_vision( HBK "$N"HBK"化作一陣輕煙，馬上就被風吹散了，而$n"HBK"沒有任何改變。\n" NOR, scroll, obj);
                                obj->add("long",
                            sprintf( HBK "[%s] 使用 %s "HBK"失敗。\n" NOR, ctime(time()), scroll->query("name")  ) );
                }
        }

        destruct(scroll);

        return 1;
}

void create() 
{ 
        seteuid(getuid()); 
}

