// combatd.c
// ��s���: 2003.06.13	�ק�H: Shengsan@ms2.url.com.tw �ק�N��: sV1
// ��s���: 1999.10.6
// �ק�H: Luky
// #pragma optimize all
//#pragma save_binary
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
// ����g��ȥ[�v�]�w
#define MOB_RECORD_MAX 30
#define EXP_GAIN_RATE 3
#define GETCOMBATEXP_ROLE	MAX_PPL_ACTION_LEVEL*3+MAX_PPL_ACTION_LEVEL/2		//sV1 //180


inherit F_DBASE;
object* enemys;
void delete_killer(object ob);
void exp_prize(int gain_exp, object killer);
void war_art_gain(int gain_exp, object killer);
	
string *catch_hunt_msg = ({
                              HIW "$N�M$n���H�ۨ����~�����M�ߨ襴�F�_�ӡT\n" NOR,
                              HIW "$N�M$n�@�I���M�G�ܤ����N���F�_�ӡT\n" NOR,
                          });

string *catch_kill_msg = ({
                              HIW "$N�����������c���ݵ�$n�M��������$n�a��T\n" NOR,
                              HIW "$N�@�ݨ�$n�K�ߨ�Ĩ�$n������T\n" NOR,
                          });

string *winner_msg = ({
                          CYN "\n$N����@���M���ۻ��D�R�����T\n\n" NOR,
                          CYN "\n$N�ӤF�o�ۡM�V���D�}�T�ءM���D�R�����T\n\n" NOR,
                      });

void create()
{
    seteuid(getuid());
    set("name", "�԰����F");
    set("id", "combatd");
    load_object("/adm/daemons/clockd"); //�Ȯɩ�b�o��.
}

string damage_msg(int damage, string type)
{
    string str;

    //	return "�y�� " + damage + " �I" + type + "�C\n";

    if( damage == 0 ) return NOR "���G�O�D�Ӥp�èS���y���ˮ`�C\n";

    if( !type ) type = "�ˮ`";
    if( damage < 5 ) str =  "�j�j�y�����L��";//sV1 5
    else if( damage < 20 ) str = "�y���@�I";//sV1 10
    else if( damage < 40 ) str = "�y���@�B";//sV1 20
    else if( damage < 80 ) str = "�y���᭫��";//sV1 40
    else if( damage < 160 ) str = "�y���Y����";//sV1 60
    else if( damage < 320 ) str = "�y���۷��Y����";//sV1 90
    else if( damage < 640 ) str = "�y���D�`�Y����";//sV1 120
    else if( damage < 1280 ) str = "�y�����i���Ϫ�";//sV1 150
    else if( damage < 2560 ) str = "�y���L�P�ۤ��Y��";//sV1 180
    else str =  "�y���|�@�L����";
    str += type + "�T";

    //	str += sprintf("(%s%d)"NOR,HIR,damage);
    return str;
}

//sV1  HP�ʤ��񪬺A���
string eff_status_msg(int ratio)
{
    if( ratio==100 ) return HIG "�믫�ܦn�M���W�@�I�ˤ]�S���C" NOR;
    if( ratio > 90 ) return HIG "���G���F�I���ˡC" NOR;
    if( ratio > 80 ) return HIY "���W���@�Ǥp�ˤf�C" NOR;
    if( ratio > 70 ) return HIY "���W���X�B�ˤf�M���L���G�ä�ê�ơC" NOR;
    if( ratio > 60 ) return HIY "���W���X�B�j�ˤf�M�ݰ_�Ӫ��p���Ӧn�C" NOR;
    if( ratio > 50 ) return HIM "�𮧲ʭ��M�ʧ@���áM�ݨӨ��Ф����C" NOR;
    if( ratio > 40 ) return HIM "�w�g�˲��ֲ֡M���b�j�O�伵�ۤ��ˤU�h�C" NOR;
    if( ratio > 30 ) return HIR "���F�۷������ˡM�u�ȷ|���ͩR�M�I�C" NOR;
    if( ratio > 20 ) return HIR "�w�g���˹L���M���G�֤���F�C" NOR;
    if( ratio > 10  ) return RED "�V���O��M�w�g�a�a�@���F�C" NOR;
    return RED "�w�g�˦b��y�����M�H�ɳ��i���_��C" NOR;
}


varargs void report_status(object ob, int effective)
{
    message_vision( "( $N" + eff_status_msg(
                        (int)ob->query("hp") * 100 / (int)ob->query("max_hp") ) + " )\n", ob);
}

varargs string status(object ob, int effective)
{
    return ob->name()+eff_status_msg((int)ob->query("hp") * 100 / (int)ob->query("max_hp") );
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
    int power;
    //int lvpower;
    power = ob->query_skill(skill);
    
    // �{�b�S���Լ��A���ݭn�A�ݾԼ��W�[power
   	// by tmr 2008/09/27
    /*
    lvpower = ob->query("combat_exp");

    if(lvpower<600000)  {
        power += (power/30000);
    }
    else if(lvpower<1500000)   {
        power += 20;//(600000/30000)
        power += ((power-600000)/90000);
    }
    else if(lvpower>=1500000)  {
        power += (20+10);//(600000/30000)+((1500000-600000)/90000)
        power += ((power-1500000)/300000);
    }*/
    return power;
    //-- sV1
}


// �򥻧����R���v 
// -tmr 2008/07/31
int basic_attack_factor(object ob) {
    int factor;
    int oblevel;        //sV1

    if( !living(ob) ) return 0;

    oblevel = (int)ob->query("level");          //sV1

    factor = 0;
    factor += ob->query_skill("combat")/15;                     //sV1 10
    factor += ob->query_temp("apply/hit");                      //�Z���R���ץ�(-50 ~ 50)
    factor += ob->query_temp("spell/hit");                      //�k�N�R���ץ�(-50 ~ 50)
    factor += ob->query_dex()/2;                                //dex �R���ץ�(0-200)
    factor += ob->query_int()/2;
//    factor += ob->query_temp("detect")*2;                     //�����ץ�
    return factor;
}


int attack_factor(object ob, string attack_skill)
{
    int factor;
    int oblevel;        //sV1

    if( !living(ob) ) return 0;

    oblevel = (int)ob->query("level");          //sV1
    factor = basic_attack_factor(ob);
    factor += skill_power(ob, attack_skill, SKILL_USAGE_ATTACK)/2;      //�ޯ�R���ץ�(0-50)
    factor = factor - (ob->query_encumbrance()/5000); // �t��
    factor = factor*oblevel/MAX_PPL_ACTION_LEVEL;               //sV1 �̷ӵ��Ť�ҭץ�
    return factor;
}


// �򥻰{���j��O
// -tmr 2008/07/31
int basic_dodge_factor(object ob) {
    int factor;
    int oblevel;        //sV1
    if( !living(ob) ) return 0;
    if( ob->query("hp") < 1) return 0;

    oblevel = (int)ob->query("level");                          //sV1
    factor = 0;
    factor += skill_power(ob, "dodge", SKILL_USAGE_DEFENSE)/2; //�ޯ�{���ץ�(0-50)
    factor += ob->query_skill("combat")/15;                     //sV1 10
    factor += ob->query_temp("apply/dodge");            // �˳ư{���ץ�(-50~50)
    factor += ob->query_temp("spell/dodge");            // �k�N�{���ץ�(-50~50)
    factor += ob->query_dex()/2;                                        // dex �{���ץ�(0-200)
     factor += ob->query_int()/2;
//    factor += ob->query_temp("invis");                                // �����ץ�(0-100)
    factor += ob->query_temp("fly")*100;                        // ����ץ� (0-100)
    return factor;
}

int dodge_factor(object ob, string dodge_skill)
{
    int factor;
    int oblevel;        //sV1

    if( !living(ob) ) return 0;
    if( ob->query("hp") < 1) return 0;

    oblevel = (int)ob->query("level");          //sV1

    factor = basic_dodge_factor(ob);
    factor = factor + (ob->query_encumbrance()/5000);
    factor = -factor;
    factor = factor*oblevel/MAX_PPL_ACTION_LEVEL;               //sV1 �̷ӵ��Ť�ҭץ�
    return factor;
}


//
// ���b����ҳy�����ˮ`
//
int Merits_damage(object me,object victim,int damage,string Merits_type)
{
    int a, b, damage2, dam_limit;

    damage2 = damage;
    if(!(Merits_type == "bio" || Merits_type == "bar" || Merits_type == "wit"
            || Merits_type == "sou" || Merits_type == "tec") )
        Merits_type = "bar";

    a = me->query_Merits(Merits_type);
    b = victim->query_Merits(Merits_type);
    damage += ( damage*( a - b ) )/7;

    if( damage < 0 )
        damage = 0;
    else if( userp(me) && userp(victim) )
        damage=damage*2/3;

    //�̤j�ˮ`����
    if(Merits_type == "wit" || Merits_type == "sou") {
            dam_limit=me->query_int()*20;   // change by -Acme-
    }
    else
    {
        if(userp(me))
            dam_limit=me->query_damage()*4;
        else
            dam_limit=me->query_damage()*4;
    }

    if(damage>dam_limit)
    	damage=dam_limit;

    if( wizardp(me) && me->query("env/debug") )
    {
        tell_object(me,HIW"  Merits_damage:"+GRN+" ["HIW+me->query("name")+GRN
                    "]����["HIW+victim->query("name")+GRN"] ��������:("HIW+Merits_type+GRN")"+
                    "  ��l�ˮ`("HIR+damage2+GRN") ==> �^�Ƕˮ`:("HIR+damage+GRN")\n"NOR);
    }
    if( wizardp(victim) && victim->query("env/debug") )
    {
        tell_object(victim,HIW"  Merits_damage:"+GRN+" ["HIW+me->query("name")+GRN
                    "]����["HIW+victim->query("name")+GRN"] ��������:("HIW+Merits_type+GRN")"+
                    "  ��l�ˮ`("HIR+damage2+GRN") => �^�Ƕˮ`:("HIR+damage+GRN")\n"NOR);
    }
    return damage;
}


//  ���b�����ˮ`�Ȫ��v�T�A��κرڨӧP�_ - by 2008/09/05
string query_attack_merits(object me) {
                // ���]�w attack merits �N�H�o�Ӭ��D
                if(me->query("attack_merits") )
                        return me->query("attack_merits");
                // �_�h�Hrace�ӧP�_
        switch( me->query("race") ) {
                case "ogre" : return "bar";
                 case "beast" : return "bio";
                case "monster" : return "bar";
                case "celestial" : return "wit";
                case "evil" : return "bio";
                case "dragon" : return "bio";
                case "tiger" : return "sou";
                case "titan" : return "tec";
        }
        // �D�̰���merits 
                if( me->query_bar() >= me->query_bio()
                        && me->query_bar() >= me->query_wit()
                        && me->query_bar() >= me->query_sou()
                        && me->query_bar() >= me->query_tec()
                ) return "bar";
                
                if( me->query_bio() >= me->query_bar()
                        && me->query_bio() >= me->query_wit()
                        && me->query_bio() >= me->query_sou()
                        && me->query_bio() >= me->query_tec()
                ) return "bio";
                if( me->query_wit() >= me->query_bio()
                        && me->query_wit() >= me->query_bar()
                        && me->query_wit() >= me->query_sou()
                        && me->query_wit() >= me->query_tec()
                ) return "wit";
                if( me->query_sou() >= me->query_bar()
                        && me->query_sou() >= me->query_bio()
                        && me->query_sou() >= me->query_wit()
                        && me->query_sou() >= me->query_tec()
                ) return "sou";
                if( me->query_tec() >= me->query_bar()
                        && me->query_tec() >= me->query_bio()
                        && me->query_tec() >= me->query_wit()
                        && me->query_tec() >= me->query_sou()
                ) return "tec";
                
                return "bar";   // default
}



// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
    mapping my, your, action;
    string limb, *limbs, result, result_damage,result_me,result_victim;
    string attack_skill, dodge_skill, parry_skill;
    string attact_type;
    mixed foo;
    mapping weapon_msg;
    int hitrole, heavy, miss;
    int damage, damage_bonus,defence;
    /*
     * �� Victim ���ĤH�W�L 10 �ӥH�W
     * �h Victim �N��פ����Ӧۥ|���K
     * �誺�����A�ӾD����ˮ`�C
     *
     *  Add By Tmr
     */
    enemys=victim->query_enemy();


    //��O�ޭ��w���ⶤ�~��I�s
    //sV1 if(me->is_team_leader() && !me->is_busy() && ( random(80) < me->query("level") || me->query_temp("combine/bonus")))
    if(me->is_team_leader() && !me->is_busy() && ( random(MAX_PPL_ACTION_LEVEL*18/10) < me->query("level") || me->query_temp("combine/bonus")))
    {
        //tell_object(me,"COMBATD�I�s combine_attack()��!\n");
        if(me->combine_attack(victim,victim->query_enemy(),"normal"))
        {
            if(me->query_temp("combine/bonus")) me->add_temp("combine/bonus",-1); //���X����
            return 1;
        }
    }

    result_damage="";
    my = me->query_entire_dbase();
    your = victim->query_entire_dbase();

    //
    // (1) Find out what action the offenser will take.
    //

    action = me->query("actions");
    if( !mapp(action) )
    {
        me->reset_action();
        action = me->query("actions");
        if( !mapp(action) )
        {
            CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s): bad action = %O",
                                   me->name(1), me->query("id"), me->query("actions", 1)));
            return 0;
        }
    }
    result = "" + action["action"] + "�T";

    //
    // (2) ��l���v�å[�H�ץ��H�P�_�O�_��R��
    //
    heavy=0;
    miss=0;
    hitrole=random(HITROLE);			// random�Ʀr�V�C �ݩʧޯ�v�T�V�j

    if(attack_type == TYPE_HEAVY)
        heavy=1;
    // �ĤH�H�ƹL�h�A�L�k��ק���
    else if( sizeof(enemys) >= MAX_ENEMYS && random(100)>70 )
        heavy=2;
    else if( me->is_busy() ) heavy = 2;   // busy �{����.. by Acme
    else if( hitrole > HITHEAVY )
        heavy=1;                 //heavy �R���n�`  else if(hitrole < HITMISS && attack_type!=TYPE_BERSERK) miss=1;         //miss  �Y������

    if( wizardp(me) && me->query("env/debug") )	//debug message 1
        message_vision(HIW"  ��l�R�����v:"+hitrole+NOR,me);

    if( objectp(weapon) )
        attack_skill = weapon->query("skill_type");
    else
        attack_skill = "unarmed";

    if(weapon) //���Z�����ۭq�T���åB�S���ϥάM�g�ޯ��, ��ΪZ���ۭq�԰��T��
    {
        if(arrayp(weapon_msg=weapon->query("combat_msg")) && !me->query_skill_mapped(attack_skill))
            result=""+weapon_msg[random(sizeof(weapon_msg))]+ "�T";
    }

    limbs = victim->query("limbs");
    if(!sizeof(limbs))
    {
        limbs=victim->query("default_limbs");
        if(!sizeof(limbs))
        {
            CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s): missing limbs. ", me->name(1), me->query("id")));
            return 0;
        }
    }
    limb = limbs[random(sizeof(limbs))];
    if( wizardp(me) && me->query("env/debug") )		//debug message 2
        message_vision(HIG"  $N�R���ץ�:+"+attack_factor(me,attack_skill)+HIR"  $n�{���ץ�:"+dodge_factor(victim,"dodge")+NOR,me,victim);

    hitrole += attack_factor(me,attack_skill);
    hitrole += dodge_factor(victim,"dodge");

    if( action["dodge"] )
    {
        if( wizardp(me) && me->query("env/debug") ) message_vision(HIR"  �ۦ��{��:-"+(int)action["dodge"]+NOR,me,victim);
        hitrole-=(int)action["dodge"];
    }
    if( action["hit"] )
    {
        if( wizardp(me) && me->query("env/debug") ) message_vision(HIG"  �ۦ��R��:+"+(int)action["hit"]+NOR,me,victim);
        hitrole+=(int)action["hit"];
    }
    if(attack_type==TYPE_BERSERK)
    {
        if( wizardp(me) && me->query("env/debug") ) message_vision(HIR"  ��������(BERSERK):-"+hitrole/20+NOR,me,victim);
        hitrole-=hitrole/20; 	//Berserk �h���������C�R���v
    }
    else if(attack_type==TYPE_QUICK)
    {
        if( wizardp(me) && me->query("env/debug") ) message_vision(HIG"  ��������(QUICK):+"+hitrole/10+NOR,me,victim);
        hitrole+=hitrole/10; //Quick �ֳt�����W�[�R���v
    }

    if( wizardp(me) && me->query("env/debug") ) message_vision(HIW"  �X�p:"+hitrole+NOR+"\n",me,victim);

    if( victim->is_busy() ) hitrole+=hitrole/5;

    if(!userp(me) && me->special_attack(me,victim,hitrole)) return 1; //�ۭq�S����, ��npc��.
    /*								*/
    /* special_attack(<obj>������,<obj>�����,<int>�R���p��)	*/
    /*								*/

    //
    // (3) Fight!
    //     �p�Ghitrole > 150 �Y���R��, <150 �h�S���R��
    //     ��heavy==1 �ɥ��w�R��, ��miss==1�� ���w����B�|�]�����~�ӳy��busy
    //
    if( ( !heavy && ( hitrole < THACO ) && !victim->query_temp("unconcious") ) || miss )  // victim�{�����\
    {
        dodge_skill = victim->query_skill_mapped("dodge");
        if( !dodge_skill ) dodge_skill = "dodge";
        result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

        //�W�[�g��ȻP�ޯ�
        if( ( random(your["level"] + my["level"]) >= your["level"] ) && ( !userp(victim) || !userp(me) ) )
        {
            if( (my["level"]>2 && your["level"]>2) || (my["exp"]*999 > your["exp"] )) //����C���Ũg�m�\�o���ɯ�
            {
                if( victim->query("int") > random(GETCOMBATEXP_ROLE) && ( your["level"]>4 || your["combat_exp"]<your["level"]*3000))// �W�[combat_exp���x����
                    your["combat_exp"] += 1+my["level"]/25;
                victim->improve_skill(dodge_skill, random( your["int"]/4 +my["level"]/3) + 1 );
                if( dodge_skill != "dodge" )
                    victim->improve_skill("dodge", random( your["int"]/4+my["level"]/3 ) + 1 );
            }
        }

        // This is for NPC only. NPC have chance to get exp when fail to hit.
        if( ( hitrole > EXPCO ) && !userp(me) )
        {
            if( me->query("int") > random(GETCOMBATEXP_ROLE) && ( my["level"]>4 || my["combat_exp"]<my["level"]*3000) )// �W�[combat_exp���x����
                my["combat_exp"] += 1+your["level"]/25;
            me->improve_skill(attack_skill, 1+random(my["int"]/4+your["level"]/3));
        }
        if(miss && !me->is_busy())
            me->start_busy(random(2)+1);
        damage = RESULT_DODGE;
        if( wizardp(me) && me->query("env/debug") )
        {
            tell_object(me, sprintf( HIG "  %s�{�����\\!!(HITROLE�R%d) \n" NOR,victim->name(),hitrole));
        }
        if( wizardp(victim) && me->query("env/debug") )
        {
            tell_object(victim, sprintf( HIG "  %s�{�����\\!!(HITROLE�R%d) \n" NOR,victim->name(),hitrole));
        }
    }
    else	//victim�{������
    {
        //
        //	(4) �ˬdvictim�O�_��۬[����
        //
        // �����P�ɮ��Z���ά޵P��, �ζüƨM�w�۬[������ by Shengsan
        if( objectp(victim->query_temp("armor/shield")) && objectp(victim->query_temp("weapon")) )
            parry_skill = (random(50)%2>0) ? "block" : "parry" ;
        else if( objectp(victim->query_temp("armor/shield")) )	//��⦳�޵P
            parry_skill = "block";
        else
        {
            if( objectp(victim->query_temp("weapon")) )	//��⦳�Z��
                parry_skill = "parry";
            else	//���S���Z��
                parry_skill = "unarmed";
        }

        hitrole = hitrole/2+random(HITROLE/2);
        if( parry_skill == "unarmed" )
            hitrole -= skill_power(victim, parry_skill, SKILL_USAGE_DEFENSE)/2;
        else
            hitrole -= skill_power(victim, parry_skill, SKILL_USAGE_DEFENSE);
        hitrole += skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
        hitrole -= victim->query_temp("apply/parry");
        hitrole += me->query_str();
        hitrole -= victim->query_str();
        if( victim->is_busy() )
            hitrole+= hitrole/5;

        //victim�۬[���\
        if( ( !heavy && ( hitrole < THACO ) && !victim->query_temp("unconcious") ) || miss )
        {
            // change to SKILL_D(parry_skill) after added parry msg to those
            // martial arts that can parry.
            if(parry_skill=="block")
            {
                parry_skill = victim->query_skill_mapped("block");
                if( !parry_skill ) parry_skill = "block";                    
                result += SKILL_D(parry_skill)->query_block_msg(victim->query_temp("armor/shield"));
            }
            else
            {
                parry_skill = victim->query_skill_mapped("parry");
                if( !parry_skill ) parry_skill = "parry"; 
                result += SKILL_D(parry_skill)->query_parry_msg(victim->query_temp("weapon"));  //�۬[�T��
            }

            if( ( random(your["level"]-my["level"]) < random(2) ) && ( !userp(victim) || !userp(me) ) )
            {
                if( victim->query("int") > random(GETCOMBATEXP_ROLE) && ( your["level"]>4 || your["combat_exp"]<your["level"]*3000))// �W�[combat_exp���x����
                    your["combat_exp"] += 1+my["level"]/25;
                victim->improve_skill(parry_skill, 1+random(your["int"]/4+my["level"]/3));
            }
            damage = RESULT_PARRY;
            if( wizardp(me) && me->query("env/debug") )
            {
                tell_object(me, sprintf( HIG "  %s�۬[���\\!!(HITROLE�R%d) \n" NOR,victim->name(),hitrole));
            }
            if( wizardp(victim) && me->query("env/debug") )
            {
                tell_object(victim, sprintf( HIG "  %s�۬[���\\!!(HITROLE�R%d) \n" NOR,victim->name(),hitrole));
            }

        }
        else
        {
            //
            //	(5) �R���ĤHvictim�Bvictim�۬[����, �}�l�p��ˮ`��
            //
            damage = me->query_damage();
            damage = damage/2 + random(damage/2);

            if( action["damage"] )
            {
                if(action["damage"]>100) action["damage"]=100;
                if(action["damage"]<-99) action["damage"]=-99;
                damage += action["damage"] * damage / 100;	//skill�ĪG�ץ�[]%
            }
            if( weapon ) {
                foo = weapon->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) )
                    result += foo;
                else if(intp(foo) )
                    damage_bonus += foo;
            }
            else
            {
                foo = me->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) )
                    result += foo;
                else if(intp(foo) )
                    damage_bonus += foo;
            }
            if( damage_bonus > 0 )
                damage += (damage_bonus + random(damage_bonus))/2;
            if(heavy)
                damage+=damage/2;

            //���m�O�p��
            defence = victim->query_armor();
            defence = defence/2+random(defence/2);
            if(damage>=defence)
                damage = defence/8 + random(defence/5) + (damage-defence)*2/3+random((damage-defence)/2);
            else
                damage = random(2+damage/7);

            //  ���b�����ˮ`�Ȫ��v�T�A��κرڨӧP�_ - by 2008/09/05
            attact_type = query_attack_merits(me);
            damage = Merits_damage(me,victim,damage,attact_type);
            if(damage <0 ) 
            	damage=1+random(me->query_str()/3)/2;
            //
            //	(6) �����ĤH�ˮ`
            //
            if(damage > 0 )
            	damage = victim->receive_damage("hp", damage, me );
            result_damage +=damage_msg(damage, action["damage_type"]);
        }
    }
    //
    //	(7) �W�[�԰����m�ȻP�ޯ�
    //
    if( !userp(me) || !userp(victim) )
    {
        if( random(your["level"] + my["level"] + 3) >= my["level"] )
        {
            if( me->query("int") > random(GETCOMBATEXP_ROLE) && ( my["level"]>4 || my["combat_exp"]<my["level"]*3000))// �W�[combat_exp���x����
                my["combat_exp"] += 1 + your["level"]/25;
            if(random(4)<1 && my["exp"]<my["level"]*500000) 			//����W�[exp�����v
                my["exp"] += random(1+your["level"]/2-my["level"]/4)+random(2); //����W�[exp���q
            me->improve_skill("combat", 1+random(my["int"]/4+my["level"]/3+your["level"]/3));
            me->improve_skill(attack_skill, 1 + random(my["int"]/4+my["level"]/3+your["level"]/3));
            if(me->query_skill_mapped(attack_skill))
                me->improve_skill(me->query_skill_mapped(attack_skill), 1+random(my["int"]/4+my["level"]/3+your["level"]/3));
        }

        if( random(your["level"] + my["level"] + 3) >= your["level"] )
        {
            if( (my["level"]>2 || your["level"]>2) || (my["exp"]*9999 > your["exp"] )) //����C���Ũg�m�\�o���ɯ�
            {
                if( victim->query("int") > random(GETCOMBATEXP_ROLE) && ( your["level"]>4 || your["combat_exp"]<your["level"]*3000) )// �W�[combat_exp���x����
                    your["combat_exp"] += 1 + my["level"]/25;
                victim->improve_skill("combat", 1+random(your["int"]/4+your["level"]/3+my["level"]/3));
            }
        }
    }

    //
    //	(8) ��ܾ԰��T��
    //
    if(heavy==1)
        result = HIM+"(�ĤO�@��)"+NOR+result;
    else if(heavy==2)
        result = HIM+"(�X��ӤJ)"+NOR+result;
    else if(miss)
        result = HIM+"(���ߤ�í)"+NOR+result;

    result = replace_string( result, "$l", to_chinese(limb) );
    result_damage = replace_string( result_damage, "$l", to_chinese(limb) );
    if( objectp(weapon) )
    {
        result = replace_string( result, "$w", weapon->name() );
        result_damage = replace_string( result_damage, "$w", weapon->name() );
    }
    else if( stringp(action["weapon"]) )
    {
        result = replace_string( result, "$w", action["weapon"] );
        result_damage = replace_string( result_damage, "$w", action["weapon"] );
    }
    result_me=result+HIY+result_damage+NOR;

    result_me = replace_string( result_me, "$N", "�A" );
    result_me = replace_string( result_me, "$n", victim->query("name") );
    result_me = replace_string( result_me, "$p", victim->query("name") );
    result_victim=result+HIR+result_damage+NOR;
    result_victim = replace_string( result_victim, "$N", me->query("name") );
    result_victim = replace_string( result_victim, "$n", "�A" );
    result_victim = replace_string( result_victim, "$p", "�A" );
    if(damage>0)
    {
        if(me->query_temp("show_damage") || me->query_temp("apply/show_damage") )
            result_me+=sprintf("(%s%d"NOR")\n",HIY,damage);
        else
            result_me+="\n";
        if(victim->query_temp("show_damage") || victim->query_temp("apply/show_damage") )
            result_victim+=sprintf("(%s%d"NOR") (%d/%d)\n",HIR,damage,your["hp"],your["max_hp"]);
        else
            result_victim+="\n";
    }
    //message_vision(result, me, victim );
    if( wizardp(me) && me->query("env/debug") )
    {
        if(damage>0)
            tell_object(me, sprintf( HIB "  [�A�����F!! %s���ˡR%d]\n" NOR, victim->name(),damage));
    }

    tell_object(me,result_me);
    if( wizardp(victim) && victim->query("env/debug") )
    {
        if(damage>0)
            tell_object(victim, sprintf( HIB "  [�A���ˤF!! �ˮ`�R%d]\n" NOR, damage));
    }
    tell_object(victim,result_victim+"\n");

    result+=CYN+result_damage+NOR+"\n";
    result = replace_string( result, "$N", me->query("name")  );
    result = replace_string( result, "$n", victim->query("name") );
    result = replace_string( result, "$p", victim->query("name") );
    tell_room(environment(me),result,({ me, victim }));

    if( damage > 0 )
    {
        if(me->query("env/report"))
            report_status(victim, damage);	//set report 1 �i�H�ݨ�report
        if( victim->is_busy() )
            victim->interrupt_me(me);
        if( (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) )	//only fight
        {
            if( victim->query("hp") < victim->query("max_hp")/2 )	//����ѤU 1/2 HP �Y����
            {
                victim->remove_enemy(me);
                me->remove_enemy(victim);
                me->set_temp("stop_fight",victim);
                message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
            }
        }
        if( damage > victim->query("max_hp")/7 )
        {
            if(random(6)==1) victim->receive_wound(limb, random(7), me );
        }
    }

    if( functionp(action["post_action"]) )
    {
        if( wizardp(me) && me->query("env/debug") ) write(HIW"post action running.....\n"NOR);
        evaluate( action["post_action"], me, victim, weapon, damage);
    } // add test msg by alickyuen@DS 2005-June-24

    // See if the victim can make a riposte.
    if( random(20) < 2 && damage < 1 && attack_type==TYPE_REGULAR  && !victim->is_busy() && !victim->is_block() )
    {
        if( random(your["dex"]) > random(my["dex"]) )
        {
            message_vision("$N�@�������M�S�X�F�}��T\n", me);
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
        }
        else
        {
            message_vision("$N��$n�������~�M�X���o�ʧ����T\n", victim, me);
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
        }
    }
}


void fight(object me, object victim)
{
      object weapon;

    if( !living(me) ) return;

    if(victim->query_temp("stop_fight")==me)
    {
        victim->delete_temp("stop_fight");
        me->remove_enemy(victim);
        return;
    }
    // If victim is busy or unconcious, always take the chance to make an attack.
    if( victim->is_busy())
        //|| !living(victim)
    {
        me->set_temp("guarding", 0);
        do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        // Else, see if we are brave enough to make an aggressive action.
    }
    else if(me->query_temp("power_cast") < 1 && me->query_temp("power_exert") < 1)
    {
        me->set_temp("guarding", 0);
        do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
          if(objectp(me) && weapon=me->query_temp("weapon"))
            weapon->attack(me,victim);
    }
    else
        return;
    // Make sure the victim had noticed the attack.
    if( !victim->is_fighting(me) )
        victim->fight_ob(me);
}

void start_berserk(object me, object obj)
{
    int bellicosity;

    if( !me || !obj ) return;			// Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if( me->is_fighting(obj)			// Are we busy fighting?
            ||  !living(me)					// Are we capable for a fight?
            ||  environment(me)!=environment(obj)		// Are we still in the same room?
            ||  environment(me)->query("no_fight")		// Are we in a peace room?
      )
        return;

    bellicosity = (int)me->query("bellicosity");
    message_vision("$N�Τ@�ز��˪����������ۦb�����C�@�ӤH�C\n", me);

    if( (int)me->query("force") > (random(bellicosity) + bellicosity)/2 )
        return;

    if( bellicosity > (int)me->query("score") && !wizardp(obj) )
    {
        message_vision("$N���$n�ܹD�R" + RANK_D->query_self_rude(me)
                       + "�ݧA��b�ܤ������M�h���a�C\n", me, obj);
        me->kill_ob(obj);
    }
    else
    {
        message_vision("$N���$n�ܹD�R�ޡT" + RANK_D->query_rude(obj)
                       + "�M" + RANK_D->query_self_rude(me) + "���Q��H���[�M���ڪ����a�T\n",
                       me, obj);
        me->fight_ob(obj);
    }
}

void start_hatred(object me, object obj)
{
    if( !me || !obj ) return;			// Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if(	me->is_fighting(obj)			// Are we busy fighting?
            ||	!living(me)				// Are we capable for a fight?
            ||	environment(me)!=environment(obj)	// Are we still in the same room?
            ||	environment(me)->query("no_fight") 	// Are we in a peace room?
            ||	!me->visible(obj)
      )	return;

    // We found our hatred! Charge!
    message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
    me->kill_ob(obj);
    me->heart_beat();
}

void start_vendetta(object me, object obj)
{
    if( !me || !obj ) return;			// Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if(	me->is_fighting(obj)			// Are we busy fighting?
            ||	!living(me)				// Are we capable for a fight?
            ||	environment(me)!=environment(obj)	// Are we still in the same room?
            ||	environment(me)->query("no_fight") 	// Are we in a peace room?
      )	return;

    // We found our vendetta opponent! Charge!
    me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
    if( !me || !obj ) return;			// Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if(	me->is_fighting(obj)			// Are we busy fighting?
            ||	!living(me)				// Are we capable for a fight?
            ||	environment(me)!=environment(obj)	// Are we still in the same room?
            ||	environment(me)->query("no_fight") 	// Are we in a peace room?
            ||	!me->visible(obj)
      )	return;

    // We got a nice victim! Kill him/her/it!!!
    me->kill_ob(obj);
}

void start_killer(object me, object obj)
{
    if( !me || !obj ) return;			// Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if(	me->is_fighting(obj)			// Are we busy fighting?
            ||	!living(me)				// Are we capable for a fight?
            ||	environment(me)!=environment(obj)	// Are we still in the same room?
            ||	environment(me)->query("no_fight") 	// Are we in a peace room?
            ||	!me->visible(obj)
      )	return;

    // We got a nice victim! Kill him/her/it!!!
    message_vision( catch_kill_msg[random(sizeof(catch_kill_msg))], me, obj);
    me->set_leader(obj);
    me->kill_ob(obj);
}
//	auto_fight()
//
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
    // Don't let NPC autofight NPC.
    if( !userp(me) && !userp(obj) ) return;

    // Because most of the cases that we cannot start a fight cannot be checked
    // before we really call the kill_ob(), so we just make sure we have no
    // aggressive callout wating here.
    if( me->query_temp("looking_for_trouble") ) return;
    me->set_temp("looking_for_trouble", 1);

    // This call_out gives victim a chance to slip trough the fierce guys.
    call_out( "start_" + type, 0, me, obj);
}
// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
    switch(event)
    {
    case "dead":
        message_vision("\n  $N�u�˦b�a�W�A���f�F�X�U...�C\n\n  $N���F�C\n\n", ob);
        break;
    case "unconcious":
        message_vision("\n  $N�}�U�@�Ӥ�í�A���˦b�a�W�A�𮧶V�ӶV�L�z�F�C\n\n", ob);
        ob->set_temp("unconcious",1);
        break;
    case "fall_sleep":
        message_vision("\n  $N���F�ӫ����A���b�a�W�I�I�j�ΤF�_�ӡC\n\n", ob);
        ob->set_temp("sleeping",1);
        break;
    case "revive":
        message_vision("\n$N�C�C�C�}�����A�M���F�L�ӡC\n\n", ob);
        ob->delete_temp("unconcious");
        break;
    case "wakeup":
        message_vision("\n$N�C�C�C�}�����A���F�L�ӡC\n\n", ob);
        ob->delete_temp("sleeping");
        break;
    }
}

void winner_reward(object killer, object victim)
{
    killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim )
{
    object *team;
      int i,bls,victim_exp,k=0,max_record,exp_rate,gain_exp;
    string vmark,mob_file,*mob_record;

    // Call the mudlib killer apply.
    killer->killed_enemy(victim);
    victim_exp=victim->query("exp");
    //�U���ˬd�Q���̬O�_�����a
    if( userp(victim) && !wizardp(victim))
    {
        if(userp(killer) &&
                !victim->query_temp("killer") &&
                !victim->query_temp("invader") &&
                killer->query_temp("invader") )   //add by linjack
        {
            killer->add_temp("killer",1);
            call_out("delete_killer", 1800, killer );
        }

        killer->add("PKS", 1);
        victim->clear_condition();

        // Give the death penalty to the dying user.
        victim->set("bellicosity", 0);
        victim->add("combat_exp", -(int)victim->query("combat_exp") / 10);
        victim->add("exp", -victim_exp / 10);
        gain_exp=victim_exp/15+random(10);
        killer->add("exp", gain_exp);
        tell_object(killer,"  �A�o�� "+gain_exp+" �I�g���!\n" );
        victim->delete("vendetta");

        if( victim->query("thief") ) victim->set("thief", (int)victim->query("thief") / 2);
        if( victim->query_temp("killer") ) victim->add_temp("killer", -1);

        //if( (int)victim->query("potential") > (int)victim->query("learned_points"))
        //	victim->add("potential",
        //	((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
        //victim->skill_death_penalty();
        //victim->spell_death_penalty();
        // �H�W���� /feature/damage.c die()
        victim->save();
        bls = 1;

        if( userp(killer) )		//PK�T��
        {
            CHANNEL_D->do_channel(this_object(), "rumor", sprintf(RED"�i����%s������R����H�g -%s"RED"- ����W�C", victim->name(1), killer->name(1)));
             RECORD_D->add_temp_record(sprintf(HIR"�i���|�s�D�j �i����%s������R����H�g -%s- ����W�C[%s]\n",
                        victim->name(1), killer->name(1), ctime(time())) );
        }

        else {
                        string msg;
                        msg = sprintf(RED"%s(%s)"RED"�Q%s"RED"�����F�C", victim->name(1), victim->query("id"), killer->name(1));
                        CHANNEL_D->do_channel(this_object(), "rumor", msg);
                          RECORD_D->add_temp_record(HIM"�i���|�s�D�j"NOR + msg + "\n");

                }
    }
    else
    {
        killer->add("MKS", 1);
        bls = 1;
    }

    // NPC got 10 times of bellicosity than user.
    //killer->add("bellicosity", bls * (userp(killer)? 1: 10));	//�W�[����

    if( stringp(vmark = victim->query("vendetta_mark")) )
        killer->add("vendetta/" + vmark, 1);

    if(userp(killer))
    {
        // ���� by Acme
        NEWQUEST_D->doKilled(victim, killer);
        if( killer->query("evil") <999 && killer->query("evil") > -999 ) //�}���ܴ�
        {
            if( victim->query("evil") > 0 || victim->query("evil") < 0 )
            {
                killer->add("evil",-victim->query("evil")/3);
            }
        }

        //����mob
        if(!userp(victim) )
        {
            /* �[�Jmob�����H�K�B�zexp�[�v�p��, ����robot */
            mob_record=killer->query("mob_record");
            mob_file=base_name(victim);
            max_record=MOB_RECORD_MAX;
            exp_rate=EXP_GAIN_RATE;

            if(sizeof(mob_record)>0)
            {
                if(sizeof(mob_record)>=max_record) mob_record=mob_record[0..(max_record-2)];
                mob_record=({mob_file})+mob_record;
            }
            else
                mob_record=({mob_file});

            killer->set("mob_record", mob_record);

            if(victim->query("level") > 3 && killer->query("level") > 3)
            {
                for(i=0;i<sizeof(mob_record) && i<max_record;i++)
                {
                    if(mob_record[i]==mob_file)
                        k++;
                }
                if( k < 1)
                    k=1;
                else if(k <= exp_rate*2)
                    k=1+k/exp_rate;
                else if( k >20)
                    k=20;
            }
            else
                k=1;

            if(team=killer->query_team())
            {
                killer->team_reward(victim,victim->query_enemy(),k);
            }
            else
            {
                gain_exp = victim_exp/k + random(20);
                if(killer->query("race")!="human")
                	gain_exp = gain_exp * 80/100;	// �䥦�رڡA�u��80%
                killer->add("exp", gain_exp);
                tell_object(killer,"  �A�o�� "+gain_exp+" �I�g���!\n" );
                exp_prize(gain_exp, killer);	// �������y
                war_art_gain(gain_exp, killer);	// �԰����N-�g���
            }
        }

        killer->save();
    }
}

/*
 * �B�~��exp�������y
 */
void exp_prize(int gain_exp, object killer)
{
	int nums;
	
    if(gain_exp < 100) return ;

    if(gain_exp%10000==7777)
    {
        tell_object(killer,HIW"  ����!! �z���F[1;5;31m��������[0m"HIW"�S�O��!!\n"HIG"  �A�o���B�~�� "+gain_exp*20+" �I�g���!\n"NOR );
        killer->add("exp", gain_exp*20);
        return;
    }

    if(gain_exp%10000==5978)
    {
        tell_object(killer,HIW"  �a�I�I�o�򢶢��I�I �z���F[0;1;5;31m?[1;5m?[1;5m?[1;5m?[1;5m?[1;5m?[1;5m?[1;5m?[0m"HIW"�W�����!!\n"HIG"  �A�o���B�~�� "+gain_exp * 20+" �I�g���!\n"NOR );
        killer->add("exp", gain_exp * 20);
        return;
    }


    if(gain_exp%1000==777)
    {
        tell_object(killer,HIW"  ����!! �z���F[1;5;31m������[0m"HIW"�S�O��!!\n"HIG"  �A�o���B�~�� "+gain_exp*5+" �I�g���!\n"NOR );
        killer->add("exp", gain_exp*5);
        return;
    }

    //++ sV1 �u�� 1 �I�g���
    if(gain_exp%1000==574)
    {
        tell_object(killer,HIW"  �u��²��!! �z���F[1;5;31m������[37m�][33m�ڥh��[37m�^[0m"HIW"�S�O���e����!!\n"HIG"  �A��誺�g��ȥu�d���A�@�I!\n"NOR );
        killer->add("exp", -gain_exp+1);
        return;
    }
    
    nums=gain_exp%1000; //�����T��
    switch(nums)
    {
    case 123:
    case 234:
    case 345:
    case 456:
    case 567:
    case 678:
    case 789:
        tell_object(killer,HIW"  ����!! �z���F[1;5;36m�P�ᶶ[0m"HIW"�S�O��!!\n"HIG"  �A�o���B�~�� "+gain_exp*2+" �I�g���!\n"NOR );
        killer->add("exp", gain_exp*2);
	    return;
    default: break;
    }
   
}


/*
 * �԰����N-�T��ɯżƭ�
 * -Tmr 2006/10/14
 */
void war_art_gain(int gain_exp, object killer)
{
	int bonus;
    if(gain_exp < 1000) {
    	bonus = 1;
    } else if(gain_exp < 5000) {
    	bonus = 3;
    } else if(gain_exp < 10000) {
    	bonus = 5;
    } else if(gain_exp < 50000) {
    	bonus = 7;
    } else if(gain_exp < 100000) {
    	bonus = 9;
    } else {
    	bonus = 11;
    }
   
	killer->add("war_score", gain_exp*bonus/100 );
    
    if( killer->query("war_score") > 10000) {
        tell_object(killer, HIW"\t\n�A�o��1�I�԰����N�C\n"NOR );
        killer->add("war_art",1);
        killer->set("war_score", killer->query("war_score") - 10000 );
    }
}

void delete_killer(object killer)
{
    if(!killer)
        return;
    if( killer->query_temp("killer") > 0 )
    {
        killer->add_temp("killer",-1);
        call_out("delete_killer", 1800, killer );
    }
    return ;
}

