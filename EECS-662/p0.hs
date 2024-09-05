{-# LANGUAGE GADTs, FlexibleContexts #-}


-- Hamza  Hameed ~~~~~~~~~~~~~~~~~~~~~~~
-- KUID: 2796053 ~~~~~~~~~~~~~~~~~~~~~~~


-- Imports for Parsec
import Control.Monad
import Text.ParserCombinators.Parsec
import Text.ParserCombinators.Parsec.Language
import Text.ParserCombinators.Parsec.Expr
import Text.ParserCombinators.Parsec.Token

--
-- Simple caculator over naturals with no identifiers
--
-- Author: Perry Alexander
-- Date: Tue Jan 23 17:54:44 CST 2018
--
-- Source files for the Arithmetic Expressions (AE) language from PLIH
--

-- AST Definition

data AE where
  Num :: Int -> AE
  Plus :: AE -> AE -> AE
  Minus :: AE -> AE -> AE
  Mult :: AE -> AE -> AE
  Div :: AE -> AE -> AE
  If0 :: AE -> AE -> AE -> AE
  deriving (Show,Eq)

-- AE Parser (Requires ParserUtils and Parsec included above)

languageDef =
  javaStyle { identStart = letter
            , identLetter = alphaNum
            , reservedNames = [ "if0"
                              , "then"
                              , "else"
                              ]
            , reservedOpNames = [ "+","-","*","/"]
            }

lexer = makeTokenParser languageDef

inFix o c a = (Infix (reservedOp lexer o >> return c) a)
preFix o c = (Prefix (reservedOp lexer o >> return c))
postFix o c = (Postfix (reservedOp lexer o >> return c))

parseString p str =
  case parse p "" str of
    Left e -> error $ show e
    Right r -> r

expr :: Parser AE
expr = buildExpressionParser operators term

operators = [
  [ inFix "*" Mult AssocLeft
    , inFix "/" Div AssocLeft ]
  , [ inFix "+" Plus AssocLeft
  , inFix "-" Minus AssocLeft ]
  ]

numExpr :: Parser AE
numExpr = do i <- integer lexer
             return (Num (fromInteger i))

ifExpr :: Parser AE
ifExpr  = do reserved lexer "if0"
             c <- expr
             reserved lexer "then"
             t <- expr
             reserved lexer "else"
             e <- expr
             return (If0 c t e)


term = parens lexer expr
       <|> numExpr
       <|> ifExpr

-- Parser invocation
-- Call parseAE to parse a string into the AE data structure.

parseAE = parseString expr

-- Evaluation Functions
-- Replace the bodies of these functions with your implementations for
-- Exercises 1-4.  Feel free to add utility functions or testing functions as
-- you see fit, but do not change the function signatures.  Note that only
-- Exercise 4 requires you to integrate the parser above.

-- Where my code begins ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

evalAE :: AE -> Int
evalAE (Num n) = if n < 0 then error "Numbers must be naturals" else n
evalAE (Plus l r) = if (evalAE l) < 0 || (evalAE r) < 0
                    then error "Numbers must be naturals"
                    else (evalAE l) + (evalAE r)
evalAE (Minus l r) = if (evalAE l) < 0 || (evalAE r) < 0
                     then error "Numbers must be naturals"
                     else (evalAE l) - (evalAE r)
evalAE (Mult l r) = if (evalAE l) < 0 || (evalAE r) < 0
                    then error "Numbers must be naturals"
                    else (evalAE l) * (evalAE r)
evalAE (Div l r) = if (evalAE l) < 0 || (evalAE r) < 0
                   then error "Numbers must be naturals"
                   else if (evalAE r) == 0
                        then error "Divide by Zero Error"
                        else (evalAE l) `div` (evalAE r)
evalAE (If0 a b c) = if (evalAE a) < 0 || (evalAE b) < 0 || (evalAE c) < 0
                     then error "Numbers must be naturals"
                     else if (evalAE a) == 0 then (evalAE b) else (evalAE c)

evalAEMaybe :: AE -> Maybe Int
evalAEMaybe (Num n) = Just n
evalAEMaybe (Plus l r) = case (evalAEMaybe l) of
                            (Just l') -> if l' < 0 then Nothing
                                                   else case (evalAEMaybe r) of
                                                            (Just r') -> if r' < 0 then Nothing
                                                                               else (Just(l' + r'))
                                                            Nothing -> Nothing
                            Nothing -> Nothing
evalAEMaybe (Minus l r) = case (evalAEMaybe l) of
                            (Just l') -> if l' < 0 then Nothing
                                                   else case (evalAEMaybe r) of
                                                            (Just r') -> if r' < 0 then Nothing
                                                                               else (Just(l' - r'))
                                                            Nothing -> Nothing
                            Nothing -> Nothing
evalAEMaybe (Mult l r) = case (evalAEMaybe l) of
                            (Just l') -> if l' < 0 then Nothing
                                                   else case (evalAEMaybe r) of
                                                            (Just r') -> if r' < 0 then Nothing
                                                                               else (Just(l' * r'))
                                                            Nothing -> Nothing
                            Nothing -> Nothing
evalAEMaybe (Div l r) = case (evalAEMaybe l) of
                            (Just l') -> if l' < 0 then Nothing
                                                   else case (evalAEMaybe r) of
                                                            (Just r') -> if r' <= 0 then Nothing
                                                                               else (Just(l' `div` r'))
                                                            Nothing -> Nothing
                            Nothing -> Nothing
evalAEMaybe (If0 a b c) = case (evalAEMaybe a) of
                          (Just a') -> case (evalAEMaybe b) of
                                       (Just b') -> case (evalAEMaybe c) of
                                                    (Just c') -> if a' == 0
                                                                 then Just b'
                                                                 else Just c'
                                                    Nothing -> Nothing
                                       Nothing -> Nothing
                          Nothing -> Nothing


evalM :: AE -> Maybe Int
evalM (Num n) = return n
evalM (Plus l r) = do {l' <- (evalM l);
                       r' <- (evalM r);
                       if l' < 0 || r' < 0 then Nothing
                       else return (l' + r')}
evalM (Minus l r) = do {l' <- (evalM l);
                       r' <- (evalM r);
                       if l' < 0 || r' < 0 then Nothing
                       else return (l' - r')}
evalM (Mult l r) = do {l' <- (evalM l);
                       r' <- (evalM r);
                       if l' < 0 || r' < 0 then Nothing
                       else return (l' * r')}
evalM (Div l r) = do {l' <- (evalM l);
                       r' <- (evalM r);
                       if l' < 0 || r' < 0 then Nothing
                       else if r' == 0 then Nothing else Just (l' `div` r')}
evalM (If0 a b c) = do {a' <- (evalM a);
                        b' <- (evalM b);
                        c' <- (evalM c);
                        if a' < 0 || b' < 0 || c' < 0 then Nothing
                        else if a' == 0 then Just b' else Just c'}

interpAE :: String -> Maybe Int
interpAE s = evalM (parseAE s)

-- Minor test cases for each eval function

evalAETest = do
             print (evalAE (Num 5))
             print (evalAE (Plus (Num 5) (Num 2)))
             print (evalAE (Minus (Num 5) (Num 2)))
             print (evalAE (Mult (Num 5) (Num 2)))
             print (evalAE (Div (Num 5) (Num 2)))
             print (evalAE (If0 (Num 0) (Num 5) (Num 2)))

evalAEMaybeTest = do
          print (evalAEMaybe (Num 5))
          print (evalAEMaybe (Plus (Num 5) (Num 2)))
          print (evalAEMaybe (Minus (Num 5) (Num 2)))
          print (evalAEMaybe (Mult (Num 5) (Num 2)))
          print (evalAEMaybe (Div (Num 5) (Num 2)))
          print (evalAEMaybe (If0 (Num 0) (Num 5) (Num 2)))

evalMTest = do
           print (evalM (Num 5))
           print (evalM (Plus (Num 5) (Num 2)))
           print (evalM (Minus (Num 5) (Num 2)))
           print (evalM (Mult (Num 5) (Num 2)))
           print (evalM (Div (Num 5) (Num 2)))
           print (evalM (If0 (Num 0) (Num 5) (Num 2)))

-- Holds the test cases together

testSuite = do
            putStrLn "---Running test suite---"
            evalAETest
            evalAEMaybeTest
            evalMTest
            putStrLn "---End Test---"

-- main just runs the test suite

main :: IO()
main = do
        testSuite
