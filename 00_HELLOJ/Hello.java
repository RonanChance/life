class Model {
	double weights[];
	Model() {
	System.out.println("Constructing a Model instance");
	}
}

class Hello {
	public static void main(String args[]) {
		System.out.println("Hello, world");
		System.out.println("Instantiating Model instance...");
		Model model = new Model();
	}
}
