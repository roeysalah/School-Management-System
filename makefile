executable_3: assignment3.o Person.o Pupil.o Teacher.o Tutor.o Class.o Layer.o Worker.o AdministrationPersonal.o Manager.o Secretary.o VecAnalyser.o School.o

	g++ assignment3.o Person.o Pupil.o Teacher.o Tutor.o Class.o Layer.o Worker.o AdministrationPersonal.o Manager.o Secretary.o VecAnalyser.o School.o -o executable_3

assignment3.o: assignment3.cpp
	g++ -c assignment3.cpp


Person.o: Person.cpp
	g++ -c Person.cpp

Pupil.o: Pupil.cpp
	g++ -c Pupil.cpp

Teacher.o: Teacher.cpp
	g++ -c Teacher.cpp

Tutor.o: Tutor.cpp
	g++ -c Tutor.cpp

Class.o: Class.cpp
	g++ -c Class.cpp

Layer.o: Layer.cpp
	g++ -c Layer.cpp

Worker.o: Worker.cpp
	g++ -c Worker.cpp

AdministrationPersonal.o: AdministrationPersonal.cpp
	g++ -c AdministrationPersonal.cpp

Manager.o: Manager.cpp
	g++ -c Manager.cpp

Secretary.o: Secretary.cpp
	g++ -c Secretary.cpp

VecAnalyser.o: VecAnalyser.cpp
	g++ -c VecAnalyser.cpp

School.o: School.cpp
	g++ -c School.cpp


clean:
	rm *.o executable_3
