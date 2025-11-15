/*

 UML Diagrams 

 1. Strucutural (static) -> How is the layout and strucute -> 7 
 2. Behaviour -> How is the interaction -> Dynamic -> 7

 we will only focus on 2 diagrams, 12 are use case based , we can skip for now

 Practically 2 are most used in interview and real life

 1. Class Diagram
 2. Sequence Diagram


 Class Digaram
 -> How to structure Classes
 -> Connection between classes

 Class is represented by a box with 3 divs
 first is car name
 second is characteristics or variables
 third is methods and behaviours

 + public
 # procected
 - private
 << abtract >> to show it is an abstract class


 How to show connection and associations

**** Inheritance i=> (is-a) relationship
 
 cow is a animal
 tiger is a animal
 monkey is a animal

 these are child and parent classes
 for (is a) relation ship we do it by arrow ----|> (this is closed triange arrow)



 ****Composition (Simple,Aggregation and composite)
 This is (has-a) relationship 
 Program is same for all three only , theory is diff slightly, how they are related
 1. simple -> Weekest or can be said the simplest
    -> Arjun and house => Ajrun lives in a house
    -> No complex relation ship just a link is present
    -> UML uses simple arow -----> for this , (open arrow)

2. Aggregation -> Little bit complex -> More complex relation ship -> two object are more interlinked
   ----<>
   diamond operator -> Aggregation relationship
   Sofa ---<> Room <>----chair
   They are part of room but they can exist individally as well

3. Composition -> Strongest form of relation ship
chair-> arms, seat, wheels,    
in this case these cannot exists without chair


arms -----<.> chair



//////////////
Sequence Diagram

-> 


*/

