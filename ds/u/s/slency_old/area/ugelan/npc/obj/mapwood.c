inherit ITEM;

void create()
{
	set_name("原木圓台", ({ "wood" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value",1);
		set("no_get",1);
	        set("long",@LONG
一個頗大的原木圓台上上畫著相當仔細的幽遮蘭城地圖。                            


                          皇廷宮門                   □
                             ｜                      ｜
           密                □                      □  □                         
           比                ｜                      ｜  ｜
           斯森－□－□－□－□－□－□－□－□－□－□－□ 
             林              ｜          ｜              ｜
                     □－□  □          □              □
                     ｜      ｜          ｜              ｜
Ｂ：銀行             □  Ｂ　Ｉ　Ｗ  Ｅ  □－Ｓ          □
Ｉ：旅店             ｜  ｜  ｜  ｜  ｜  ｜                ＼
Ｗ：武器店           □－□－□－□－□－□                  □
Ｅ：防具店                   ｜        
Ｓ：當鋪                     □
　　　　　　　　　　　　　　 ｜
                     □－□－□－□－□－□
                             ｜            ＼
                         □－□－□          □
　　　　　　　　　　　　　　 ｜
                             □
                               ＼
                                 □－□
                                       ＼
                                         □－□－預定出口
LONG
);
	set("unit","塊");
        }     
}        
                       	