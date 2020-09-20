std::string declareWinner(Fighter* fighter1, Fighter* fighter2, std::string firstAttacker)
{
  int times_to_death1 = fighter1->getHealth()/fighter2->getDamagePerAttack() + 
                        ((fighter1->getHealth()%fighter2->getDamagePerAttack()>0)?1:0);
  int times_to_death2 = fighter2->getHealth()/fighter1->getDamagePerAttack() + 
                        ((fighter2->getHealth()%fighter1->getDamagePerAttack()>0)?1:0);
                       
   if (times_to_death1 > times_to_death2)      return fighter1->getName();
   else if (times_to_death1 < times_to_death2) return fighter2->getName();
   else 
       return (firstAttacker==fighter1->getName()) ? fighter1->getName() : fighter2->getName();
   
                        
}
