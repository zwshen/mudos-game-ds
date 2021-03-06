// attribute.c

// update 2009/05/04 - Tmr
//        獸性(BAR)：每點增加 攻擊力 4%
//        生物(BIO)：每點增加 物理防禦 4%
//        魔法(WIT)：每點增加 攻擊力 4%
//        心靈(SOU)：每點增加 魔法防禦 4%
//        科技(TEC)：每點增加 物理防禦 2%，物理防禦 2%

//        獸性(BAR)：每3點增加 暴擊傷害 1%
//        魔法(WIT)：每3點增加 暴擊傷害 1% 
//        生物(BIO)：每點增加  暴擊傷害 1% 
//        心靈(SOU)：每3點增加 暴擊傷害 2% 暴擊抵抗 1%
//        科技(TEC)：每3點增加 暴擊傷害 1% 暴擊抵抗 2%

#include <dbase.h>

// 基本暴擊傷害 
#define DEFAULT_HIT_POWER 10

int query_str();
int query_con();
int query_int();
int query_dex();

int query_bar();
int query_bio();
int query_wit();
int query_sou();
int query_tec();

int query_total_gift()  //傳回屬性總和 (用於升屬性檢查)
{
        return (int)query("str")
                +(int)query("con")
                +(int)query("dex")
                +(int)query("int");
}


int query_damage()      //傳回物理性攻擊力
{
        int value = (int)query_temp("apply/damage")
                + query_temp("spell/damage")
                + query("addition_damage")      //for NPC
                + (int)(query_str())
                + 2;                            // 加強PPL&NPC的攻擊力, 以縮短戰鬥時間
                
        return (value + value*query_bar()*4/100 + value*query_wit()*4/100);
}

int query_armor()       //傳回物理性防禦力
{
        int value = (int)query_temp("apply/armor")
                + query_temp("spell/armor")
                + query("addition_armor");      //for NPC
                
                return (value + value * query_bio()*4/100 + value * query_tec()*2/100);
}

int query_shield()      //傳回非物理性防禦力(魔法抵抗力)
{
        int value = (int)query_temp("apply/shield")
                + query_temp("spell/shield")
                + query("addition_shield")      //for NPC
                + query_int();
        
        return (value + value*query_sou()*4/100 + value*query_tec()*2/100);
}

int query_str()         //傳回STR(力量)值(包含附加效果)
{
        int i,j,k,l=0;
        string *eff_limbs;
 
        i = query("str")
                + query_temp("apply/str")
                + query_temp("spell/str")
                + query("addition/str");
        eff_limbs=query("limbs_effect/str");
        j=sizeof(eff_limbs);
        if(j)
        {
                for(k=0;k<j;k++)
                {
                        l+=query("wound/"+eff_limbs[k]);
                }
                l/=j;
                i = i - (i * l)/110;
        }
        return i;
}

int query_int()         //傳回INT(智慧)值(包含附加效果)
{
        int i,j,k,l=0;
        string *eff_limbs;
        i = query("int")
                + query_temp("apply/int")
                + query_temp("spell/int")
                + query("addition/int");
        eff_limbs=query("limbs_effect/int");
        j=sizeof(eff_limbs);
        if(j)
        {
                for(k=0;k<j;k++)
                {
                        l+=query("wound/"+eff_limbs[k]);
                }
                l/=j;
                i = i - (i * l)/110;
        }
        return i;
}

int query_dex()         //傳回DEX(敏捷)值(包含附加效果)
{
        int i,j,k,l=0;
        string *eff_limbs;
        i = query("dex")
                + query_temp("apply/dex")
                + query_temp("spell/dex")
                + query("addition/dex");
        eff_limbs=query("limbs_effect/dex");
        j=sizeof(eff_limbs);
        if(j)
        {
                for(k=0;k<j;k++)
                {
                        l+=query("wound/"+eff_limbs[k]);
                }
                l/=j;
                i = i - (i * l)/110;
        }
        return i;       
}

int query_con()         //傳回CON(體質)值(包含附加效果)
{
        int i,j,k,l=0;
        string *eff_limbs;
        i = query("con")
                + query_temp("apply/con")
                + query_temp("spell/con")
                + query("addition/con");
        eff_limbs=query("limbs_effect/con");
        j=sizeof(eff_limbs);
        if(j)
        {
                for(k=0;k<j;k++)
                {
                        l+=query("wound/"+eff_limbs[k]);
                }
                l/=j;
                i = i - (i * l)/110;
        }
        return i;
}

int query_bio()         // 回傳 Biological(生物) 值
{
	return query("Merits/bio")+query_temp("apply/bio")
        + query_temp("spell/bio")+query("addition/bio");
}

int query_bar()         // 回傳 Barbarity(獸性) 值
{
	return query("Merits/bar")+query_temp("apply/bar")
        + query_temp("spell/bar")+query("addition/bar");
}


int query_wit()         // 回傳 Witchcraft(魔法) 值
{
		return query("Merits/wit")+query_temp("apply/wit")
        + query_temp("spell/wit")+query("addition/wit");
}

int query_sou()         // 回傳 Soul(心靈) 值
{
		return query("Merits/sou")+query_temp("apply/sou")
        + query_temp("spell/sou")+query("addition/sou");
}


int query_tec()         // 回傳 Technology(科技) 值
{
       return query("Merits/tec")+query_temp("apply/tec")
        + query_temp("spell/tec")+query("addition/tec");
}

int query_total_merits()        // 回傳所有素質的總和
{
       return query_bio()+query_bar()+query_wit()
        +query_sou()+query_tec();
}

int query_Merits(string Merits_type)
{
        switch(Merits_type)
        {
                case "bio": return query_bio(); break;
                case "bar": return query_bar(); break;
                case "wit": return query_wit(); break;
                case "sou": return query_sou(); break;
                case "tec": return query_tec(); break;
                default : return 0;
        }
}

// 暴擊率
int query_hit() {
	int tt;
	tt = query_str() + query_con() + query_int() + query_dex();
	return tt/100 + 
		query_temp("apply/hit_ratio") + 
			this_object()->query_skill("constant-virtue")/10;
}

// 暴擊傷害
int query_hitpower() {
	return DEFAULT_HIT_POWER + query_temp("apply/hit_power")
	+ query_bio()*3 
	+ query_sou()/3*6
	+ query_bar() + 
	query_wit() + 
	query_tec() +
          this_object()->query_skill("constant-virtue")/2;
}

// 暴擊抵抗
int query_hit_against() {
	return query_temp("apply/hit_against") 
		+ query_sou()/3 
		+ query_tec()/3*2+
		this_object()->query_skill("constant-virtue")/10;
}

// 命中率
int query_accuracy() {
	return 0;
}
