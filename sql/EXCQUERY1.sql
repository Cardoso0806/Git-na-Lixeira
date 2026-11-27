-- Encontre os nomes de todos os Juniors (nível = JR) que estão matriculados em um curso
-- ministrado por Ivana Teach.
SELECT A.nomeAlun FROM ALUNO A, MATRICULADO M, CURSO C, PROFESSOR P 
WHERE A.nivel = "JR" AND A.nroAlun = M.nroAlun AND M.nomeCurso = C.nome AND C.idProf = P.idProf AND P.nomeProf = "Ivana Teach";

-- Encontre a idade do aluno mais velho que é formado em History ou matriculado em um
-- curso ministrado por Ivana Teach.
SELECT MAX(A.idade) FROM ALUNO A, MATRICULADO M, CURSO C, PROFESSOR P 
WHERE A.formacao = "History" OR (A.nroAlun = M.nroAlun AND M.nomeCurso = C.nome AND C.idProf = P.idProf AND P.nomeProf = "Ivana Teach");

-- Encontre os nome de todos os cursos que são ministrados na sala R128 ou que têm cinco
-- ou mais alunos matriculados.
SELECT C.nome FROM CURSO C WHERE C.sala = "R128" OR C.nome IN 
(SELECT M.nomeCurso FROM MATRICULADO M GROUP BY M.nomeCurso HAVING COUNT(*) >= 5);

-- Encontre os nomes de todos os alunos que estão matriculados em dois cursos que são
-- ministrados no mesmo horário.
SELECT DISTINCT(M1.nroAlun) FROM MATRICULADO M1, MATRICULADO M2 INNER JOIN 
(SELECT C1.nome as C1, C2.nome as C2 FROM CURSO C1, CURSO C2 WHERE C1.horario = C2.horario AND C1.nome != C2.nome) CC  
WHERE M1.nroAlun = M2.nroAlun AND M1.nomeCurso = CC.C1 AND M2.nomeCurso = CC.C2;

-- Encontra todos os cursos concorrentes
SELECT C1.nome as C1, C2.nome as C2 FROM CURSO C1, CURSO C2 WHERE C1.horario = C2.horario AND C1.nome != C2.nome;

-- Encontre os nomes dos professores que ministram cursos em todas as salas em que algum
-- curso é ministrado.
SELECT P.nomeProf FROM PROFESSOR P 
WHERE NOT EXISTS ((SELECT C.sala FROM CURSO C) EXCEPT (SELECT C.sala FROM CURSO C WHERE P.idProf = C.idProf ));

-- Encontre os nomes dos professores para os quais a lista de matriculados dos cursos que
-- eles ministram é menor do que cinco.
SELECT P.nomeProf FROM CURSO C, PROFESSOR P 
WHERE C.idProf = P.idProf AND 
(SELECT COUNT(*) FROM ALUNO A, MATRICULADO M WHERE A.nroAlun = M.nroAlun AND C.nome = M.nomeCurso GROUP BY M.nomeCurso) > 5;

-- Imprima o nível e a idade média dos alunos desse nível, para cada nível.
SELECT A.nivel, AVG(A.idade) FROM ALUNO A GROUP BY A.nivel ;

-- Imprima o nível e a idade média dos alunos desse nível, para todos os níveis exceto JR.
SELECT A.nivel, AVG(A.idade)
FROM ALUNO A WHERE A.nivel != 'JR' GROUP BY A.nivel; 

-- Para cada professor que ministra cursos apenas na sala R128, imprima seu nome e o número
-- total de cursos que ele ou ela ministra.
SELECT P.nomeProf, P.idProf, count(C.nome)
FROM PROFESSOR P, CURSO C 
WHERE P.idProf = C.idProf AND P.idProf IN (
SELECT C.idProf
FROM CURSO C
WHERE C.sala = 'R128' AND
C.idProf NOT IN (SELECT DISTINCT(C.idProf) FROM CURSO C
			 WHERE C.sala != 'R128' AND C.idProf NOT IN 
			 (SELECT DISTINCT(P2.idProf) FROM PROFESSOR P2
			 WHERE P2.idProf NOT IN 
			 (SELECT DISTINCT(C.idProf) FROM CURSO C WHERE C.sala = 'R128')))
) GROUP BY P.idProf; 

-- Encontre os nomes dos alunos matriculados no número máximo de cursos.
SELECT A.ra , A.count 
FROM (SELECT M.nroAlun as ra, count(*) as count
	FROM ALUNO A, MATRICULADO M
    WHERE A.nroAlun = M.nroAlun
    GROUP BY M.nroAlun) A,
    (SELECT max(B.count) as mxm
	FROM (SELECT count(*) as count FROM ALUNO A, MATRICULADO M WHERE A.nroAlun = M.nroAlun GROUP BY M.nroAlun) B) C
WHERE C.mxm = A.count; 
	
-- Encontre os nomes dos alunos não matriculados em nenhum curso.
SELECT A.nomeAlun FROM ALUNO A WHERE A.nroAlun NOT IN (SELECT A.nroAlun FROM ALUNO A, MATRICULADO M WHERE A.nroAlun = M.nroAlun);

-- Para cada valor de idade que aparece em Aluno, encontre o valor do nível que aparece com
-- mais frequência. Por exemplo, se houver mais alunos no nível FR com idade 18 do que
-- alunos com idade 18 dos níveis SR, JR ou SR, você deve imprimir o par (18, FR).
SELECT DISTINCT(A.nivel), A.idade
FROM ALUNO A
WHERE A.idade = (
SELECT B.idade
FROM (SELECT A2.idade as idade, Count(A2.idade) as count
	  FROM ALUNO A2
	  WHERE A2.nivel = A.nivel
	  Group By A2.idade) B
WHERE B.count = (SELECT Max(C.count) FROM (SELECT Count(A2.idade) as count
											FROM ALUNO A2
					  						WHERE A2.nivel = A.nivel
					  						Group By A2.idade) 
					  						C));