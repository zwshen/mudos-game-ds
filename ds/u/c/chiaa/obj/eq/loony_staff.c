//u/c/chiaa/obj/eq/loony_staff.c
#include <ansi.h>
#include <weapon.h>  //定義是武器

inherit STAFF;

void create()
{
   set_name( MAG "狂" WHT "魔" HIW "槍" NOR, ({ "loony_staff", "staff" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("unit", "根");
  set("long", "霸王橫千秋的隨身武器,散發出一股殺氣。\n");
  set("value", 8000);
  set("material", "steel");  //材質 鋼
  set("limit_str",20);  //限制臂力20
  set("wield_msg", "$N抽出背上的$n,頓時感覺有股惡氣竄出。\n");
  set("unwield_msg", "$N將手中的$n放回背上,心裡平靜不少。\n"); 
  //$N玩家$n武器
        }

        init_staff(666); //攻擊力
 set("weapon_prop/staff", 20);      //加 enable 技能20
 set("weapon_prop/dodge", -5);      //減 enable 技能5
        setup();
}
