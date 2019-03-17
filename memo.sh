#!/bin/zsh 
vim -c 'e main/GeneticAlgorithm.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |

  tabnew | e src/GeneticAlgorithm.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/GeneticAlgorithm.hpp |

  tabnew | e src/Population.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/Population.hpp 

  tabnew | e src/Individual.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/Individual.hpp | 

  tabnew | e src/Chromosome.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/Chromosome.hpp |

  tabnew | e src/Gene.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/Gene.hpp | 

  tabnew | e src/Log.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/Log.hpp |

  tabnew | e src/LogSystem.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/LogSystem.hpp |

  tabnew | e src/LogQueue.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/LogQueue.hpp |

  tabnew | e src/LogInstance.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/LogInstance.hpp |

  tabnew | e src/Define.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/Define.hpp |
 
  tabnew | e src/Options.cpp |
  let b:syntastic_cpp_cflags = "-std=c++17 -std=gnu++17 -stdlib=libc++" |
  sp include/Options.hpp |
 
  tabnext
  '
