# Debt Simplification Command Line Tool (CLI)

---
## Motivation

---
There is a *communal ledger* shared between a couple of 
people, let's say between a group of friends, and now
they want to settle the debts in the most efficient way. (i.e. 
in the minimum total number of transactions so that there is no debt between any pair) 

*Definitions*:  
communal ledger: a book shared between a community that keeps track of the financial accounts.  
(i.e. how much does person A owe person B)

## Proposal

---
In order not to introduce ambiguity and distrust between members, we will add a 
constraint that goes like this,  
"If A didn't owe B anything in the original edger, A will not owe B anything in the simplified ledger."  
This will also prove to be useful from an algorithmic standpoint.

*Example 1*:    

*Orginal ledger*:  
Gohary owes Abu-kamal $15  
Abu-kamal owes Yasser $15

One can say that now Gohary owes Yasser $15 and that's it.  
And while the number of transaction decreased, 
this is a violation of the rule we set, since Gohary didn't owe anything to Yasser before.  

---

*Example 2*:  

*Original ledger*:  
Gohary owes Hussein $20  
Gohary owes Belal $15  
Belal owes Hussein $80

*Simplifed ledger*:  
Gohary owes Hussein $35  
Belal owes Hussein $65  

This is a valid simplification as both Gohary and Belal owed Hussein some amount in the original ledger.  

## Usage 

---

Open the terminal and run the following command

```
git clone https://github.com/AhmedEl-Gohary/debt-simplifier-cli
```  

You can either run the executable file *main* or compile locally using the following command

```
g++ -std=c++20 debt-simplifier-cli/src/*.cpp -o main
```

The simplifier takes either 1 or 2 arguments, the original ledger file and an output file for the simplified ledger.  
Note that if the second argument is not given the simplified ledger will be written to the standard output.  

Ledger file format
```
<debtor name> <creditor name> <amount of money>
```

meaning that *debtor* owes *creditor* amount of money  

---

To run the code locally, first create the original_ledger.txt file then run the following command

```
./main original_ledger.txt
```

If you want the simplified ledger to be written into a file run the following command instead

```
./main original_ledger.txt simplified_ledger.txt
```



