{-# LANGUAGE GADTs, FlexibleContexts #-}

-- Imports for Monads

import Control.Monad

-- AST Definition

data TABE where
  TNum :: TABE
  TBool :: TABE
  deriving (Show,Eq)

data ABE where
  Num :: Int -> ABE
  Plus :: ABE -> ABE -> ABE
  Minus :: ABE -> ABE -> ABE
  Mult :: ABE -> ABE -> ABE
  Div :: ABE -> ABE -> ABE
  Boolean :: Bool -> ABE
  And :: ABE -> ABE -> ABE
  Leq :: ABE -> ABE -> ABE
  IsZero :: ABE -> ABE
  If :: ABE -> ABE -> ABE -> ABE
  deriving (Show,Eq)

liftPlus::ABE -> ABE -> ABE
liftPlus (Num l) (Num r) = (Num (l+r))
liftMinus::ABE -> ABE -> ABE
liftMinus (Num l) (Num r) = (Num (l-r))
liftMult::ABE -> ABE -> ABE
liftMult (Num l) (Num r) = (Num (l*r))

-- Evaluation Functions

evalM :: ABE -> (Maybe ABE)
evalM (Num n) = Just (Num n)
evalM (Plus l r) = do {(Num l') <- (evalM l);
                       (Num r') <- (evalM r);
                       if l' < 0 || r' < 0 then Nothing
                       else return (Num (l' + r'))}
evalM (Minus l r) = do {(Num l') <- (evalM l);
                        (Num r') <- (evalM r);
                        if l' < 0 || r' < 0 then Nothing
                        else return (Num (l' - r'))}
evalM (Mult l r) = do {(Num l') <- (evalM l);
                       (Num r') <- (evalM r);
                       if l' < 0 || r' < 0 then Nothing
                       else return (Num (l' * r'))}
evalM (Div l r) = do {(Num l') <- (evalM l);
                      (Num r') <- (evalM r);
                      if l' < 0 || r' <= 0 then Nothing
                      else return (Num (l' `div` r'))}
evalM (Boolean b) = Just (Boolean b)
evalM (And l r) = do {(Boolean l') <- (evalM l);
                      (Boolean r') <- (evalM r);
                      return (Boolean (l' && r'))}
evalM (Leq l r) = do {(Num l') <- (evalM l);
                      (Num r') <- (evalM r);
                      if l' < 0 || r' < 0 then Nothing
                      else return (Boolean (l' <= r'))}
evalM (IsZero a) = do {(Num a') <- (evalM a);
                       if a' < 0 then Nothing
                       else return (Boolean (a' == 0))}
evalM (If a b c) = do {(Boolean a') <- (evalM a);
                       if a' then (evalM b) else (evalM c)}

evalErr :: ABE -> (Maybe ABE)
evalErr (Num n) = Just (Num n)
evalErr (Plus l r) = do {(Num l') <- (evalErr l);
                       (Num r') <- (evalErr r);
                       if l' < 0 || r' < 0 then Nothing
                       else return (Num (l' + r'))}
evalErr (Minus l r) = do {(Num l') <- (evalErr l);
                        (Num r') <- (evalErr r);
                        if l' < 0 || r' < 0 then Nothing
                        else return (Num (l' - r'))}
evalErr (Mult l r) = do {(Num l') <- (evalErr l);
                       (Num r') <- (evalErr r);
                       if l' < 0 || r' < 0 then Nothing
                       else return (Num (l' * r'))}
evalErr (Div l r) = do {(Num l') <- (evalErr l);
                      (Num r') <- (evalErr r);
                      if l' < 0 || r' <= 0 then Nothing
                      else return (Num (l' `div` r'))}
evalErr (Boolean b) = Just (Boolean b)
evalErr (And l r) = do {(Boolean l') <- (evalErr l);
                      (Boolean r') <- (evalErr r);
                      return (Boolean (l' && r'))}
evalErr (Leq l r) = do {(Num l') <- (evalErr l);
                      (Num r') <- (evalErr r);
                      if l' < 0 || r' < 0 then Nothing
                      else return (Boolean (l' <= r'))}
evalErr (IsZero a) = do {(Num a') <- (evalErr a);
                         if a' < 0 then Nothing
                         else return (Boolean (a' == 0))}
evalErr (If a b c) = do {(Boolean a') <- (evalErr a);
                       if a' then (evalErr b) else (evalErr c)}

-- Type Derivation Function

typeofM :: ABE -> Maybe TABE
typeofM (Num n) = Just TNum
typeofM (Plus l r) = do {TNum <- typeofM l;
                         TNum <- typeofM r;
                         return TNum}
typeofM (Minus l r) = do {TNum <- typeofM l;
                          TNum <- typeofM r;
                          return TNum}
typeofM (Mult l r) = do {TNum <- typeofM l;
                         TNum <- typeofM r;
                         return TNum}
typeofM (Div l r) = do {TNum <- typeofM l;
                        TNum <- typeofM r;
                        return TNum}
typeofM (Boolean b) = Just TBool
typeofM (And l r) = do {TBool <- typeofM l;
                        TBool <- typeofM r;
                        return TBool}
typeofM (Leq l r) = do {TNum <- typeofM l;
                        TNum <- typeofM r;
                        return TBool}
typeofM (IsZero a) = do {TNum <- typeofM a;
                         return TBool}
typeofM (If a b c) = do {TBool <- typeofM a;
                         if (typeofM b == typeofM c)
                         then (typeofM b) else Nothing}
-- Combined interpreter

evalTypeM :: ABE -> Maybe ABE
evalTypeM e = do {t <- typeofM e;
                  evalM e}

-- Optimizer

optimize :: ABE -> ABE
optimize e = case e of
                (Plus l (Num 0)) -> l
                (Plus (Num 0) r) -> r
                (If (Boolean True) x y) -> x
                (If (Boolean False) x y) -> y

interpOptM :: ABE -> Maybe ABE
interpOptM e = evalM (optimize e)

main::IO()
main = do
        print (evalM (Num 0))
        print (typeofM (Num 0))
        print (typeofM (Plus (Num 0) (Num 1)))
