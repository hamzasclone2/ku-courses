{-# LANGUAGE GADTs,FlexibleContexts #-}

-- Imports for Monads

import Control.Monad

-- BBAE AST and Type Definitions

data TBBAE where
  TNum :: TBBAE
  TBool :: TBBAE
  deriving (Show,Eq)

data BBAE where
  Num :: Int -> BBAE
  Plus :: BBAE -> BBAE -> BBAE
  Minus :: BBAE -> BBAE -> BBAE
  Bind :: String -> BBAE -> BBAE -> BBAE
  Id :: String -> BBAE
  Boolean :: Bool -> BBAE
  And :: BBAE -> BBAE -> BBAE
  Leq :: BBAE -> BBAE -> BBAE
  IsZero :: BBAE -> BBAE
  If :: BBAE -> BBAE -> BBAE -> BBAE
  deriving (Show,Eq)

type Env = [(String,BBAE)]

type Cont = [(String,TBBAE)]

subst :: String -> BBAE -> BBAE -> BBAE
subst i v (Num n) = (Num n)
subst i v (Plus l r) = (Plus (subst i v l) (subst i v r))
subst i v (Minus l r) = (Minus (subst i v l) (subst i v r))
subst i v (Bind i' v' e') = if i == i' then (Bind i' (subst i v v') e')
                                       else (Bind i' (subst i v v') (subst i v e'))
subst i v (Id i') = if i == i' then v else (Id i')
subst i v (Boolean b) = (Boolean b)
subst i v (And l r) = (And (subst i v l) (subst i v r))
subst i v (Leq l r) = (Leq (subst i v l) (subst i v r))
subst i v (IsZero a) = (IsZero (subst i v a))
subst i v (If a b c) = (If (subst i v a) (subst i v b) (subst i v c))

evalS :: BBAE -> (Maybe BBAE)
evalS (Num n) = Just (Num n)
evalS (Plus l r) = do {(Num l') <- (evalS l);
                       (Num r') <- (evalS r);
                       if l' < 0 || r' < 0 then Nothing
                       else return (Num (l' + r'))}
evalS (Minus l r) = do {(Num l') <- (evalS l);
                        (Num r') <- (evalS r);
                        if l' < 0 || r' < 0 then Nothing
                        else return (Num (l' - r'))}
evalS (Bind i v e) = do{v' <- (evalS v);
                        evalS (subst i v' e)}
evalS (Id i) = Nothing
evalS (Boolean b) = Just (Boolean b)
evalS (And l r) = do {(Boolean l') <- (evalS l);
                      (Boolean r') <- (evalS r);
                      return (Boolean (l' && r'))}
evalS (Leq l r) = do {(Num l') <- (evalS l);
                      (Num r') <- (evalS r);
                      if l' < 0 || r' < 0 then Nothing
                      else return (Boolean (l' <= r'))}
evalS (IsZero a) = do {(Num a') <- (evalS a);
                       if a' < 0 then Nothing
                       else return (Boolean (a' == 0))}
evalS (If a b c) = do {(Boolean a') <- (evalS a);
                       if a' then (evalS b) else (evalS c)}

evalM :: Env -> BBAE -> (Maybe BBAE)
evalM e (Num n) = Just (Num n)
evalM e (Plus l r) = do {(Num l') <- evalM e l;
                         (Num r') <- evalM e r;
                         return (Num(l' + r'))}
evalM e (Minus l r) = do {(Num l') <- evalM e l;
                          (Num r') <- evalM e r;
                          return (Num(l' - r'))}
evalM e (Bind i v t) = do{v' <- evalM e v;
                          evalM ((i, v'):e) t}
evalM e (Id i) = lookup i e
evalM e (Boolean b) = Just (Boolean b)
evalM e (And l r) = do {(Boolean l') <- (evalM e l);
                      (Boolean r') <- (evalM e r);
                      return (Boolean (l' && r'))}
evalM e (Leq l r) = do {(Num l') <- (evalM e l);
                      (Num r') <- (evalM e r);
                      if l' < 0 || r' < 0 then Nothing
                      else return (Boolean (l' <= r'))}
evalM e (IsZero a) = do {(Num a') <- (evalM e a);
                       if a' < 0 then Nothing
                       else return (Boolean (a' == 0))}
evalM e (If a b c) = do {(Boolean a') <- (evalM e a);
                       if a' then (evalM e b) else (evalM e c)}

testBBAE :: BBAE -> Bool
testBBAE a = if evalM [] a == evalS a then True else False

typeofM :: Cont -> BBAE -> (Maybe TBBAE)
typeofM c (Num n) = Just TNum
typeofM c (Plus l r) = do {TNum <- typeofM c l;
                         TNum <- typeofM c r;
                         return TNum}
typeofM c (Minus l r) = do {TNum <- typeofM c l;
                          TNum <- typeofM c r;
                          return TNum}
typeofM c (Bind i v t) = do {TNum <- typeofM c (Id i);
                             TNum <- typeofM c v;
                             TNum <- typeofM c t;
                             return TBool}
typeofM c (Id i) = do {TNum <- typeofM c (Id i);
                       return TNum}
typeofM c (Boolean b) = Just TBool
typeofM c (And l r) = do {TBool <- typeofM c l;
                        TBool <- typeofM c r;
                        return TBool}
typeofM c (Leq l r) = do {TNum <- typeofM c l;
                        TNum <- typeofM c r;
                        return TBool}
typeofM c (IsZero a) = do {TNum <- typeofM c a;
                         return TBool}
typeofM c (If a b c') = do {TBool <- typeofM c a;
                         if (typeofM c b == typeofM c c')
                         then (typeofM c b) else Nothing}

evalT :: BBAE -> (Maybe BBAE)
evalT a = do {typeofM [] a;
              evalM [] a}

main :: IO()
main = do
    putStrLn "-Project 2-"
