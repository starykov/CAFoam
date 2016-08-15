Info<< "Reading field index \n" << endl;

volScalarField index
(
    IOobject
    (
        "index",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField nextIndex
(
    IOobject
    (
        "nextIndex",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
	index
);

Info<< "Reading CA Properties \n" << endl;
IOdictionary CAProperties
(
     IOobject
     (
          "CAProperties",
          runTime.constant(),
          mesh,
          IOobject::MUST_READ,
          IOobject::NO_WRITE
     )
);

int numOrientations = CAProperties.lookupOrDefault<int>("numOrientations", 10);
int numGrains = CAProperties.lookupOrDefault<int>("numGrains", 10);

time_t t;
srand((unsigned) time(&t));

Info<< "Initializing fields" << endl;
for (int i=0; i<numGrains; i++)
{
//	Info<< "test1" << endl;
	int cell = rand() % mesh.cells().size();
//	Info<< "cell " << rand() % mesh.cells().size() << endl;

	int value = rand() % numOrientations;
//	Info<< "value " << rand() % numOrientations << endl;

	index[cell]=value;
//	Info<< "test4" << endl;

}
Info<< "Everything ok" << endl;
